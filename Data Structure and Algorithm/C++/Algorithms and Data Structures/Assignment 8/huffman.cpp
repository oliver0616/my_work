// CSCI 2530
// Assignment: programming assignment 8
// Author:     Huan-Yun Chen
// File:       huffman.cpp
// Tab stops:  4
// **Implementation of the data compression with Huffman's Algorithm**
//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "pqueue.h"
#include "trace.h"
#include "binary.h"

//---------------------------------------------------------------------------

// This function computes the frequencies of the characters given the FILE
// pointer fp.
// Frequency *table : store the frequency counts, one for each possible
//                    character that can be stored in one byte.
void computeFrequency(FILE *fp, Frequency *table)
{
	// setting all of the character frequencies to 0
	for(int i = 0; i < NUMBER_OF_CHARS; i++)
	{
		table[i].v=0;
		table[i].c=i;
	}
	//  computes the character counts
	while(1)
	{
		int c = fgetc(fp);
		if(feof(fp))break;
		(table[c].v)++;
	}
}

// This function takes the array of character frequencies and returns
// a huffman tree based on the character frequencies.
Tree buildHuffmanTree(Frequency *table)
{
	PriorityQueue q;        // create a priority queue

	// Insert a leaf into the priority queue for each character
	// whose frequency is not 0, with its frequency as its priority
	for(int i = 0; i < NUMBER_OF_CHARS; i++){
		if( (table[i].v) > 0 )
		{
			Tree t = new Node(table[i].c);
			insert(t,table[i].v,q);
		}
	}

	// Repeatedly remove two trees from the priority queue.
	// Combine them into a single tree.
	while (1)
	{
		PQPriorityType lf,rf,F;
		if (q.queue->next==NULL)
		{
			return q.queue->item;
			break;
		}
		Tree L,R,tt;
		remove(L,lf,q);
		remove(R,rf,q);
		// creates a new tree with left subtree and right subtree.
		tt = new Node(L, R);
		F=lf+rf;
		insert(tt,F,q);
	}
}

// takes the Huffman tree t and an array codeTable that can hold 256 strings.
// Tree t: A tree t (a subtree of the full huffman tree)
// char codeTable[][256]: The array Code to fill with the code.
// char pref[]: A null-terminated string pref of 0's and 1's that is the sequence
//              of edge labels from the root of the huffman tree to the root of t.
void buildCode(Tree t, char codeTable[][256],  char pref[])
{
	char temp[256];
	// If t is a leaf holding character c, then add pref into codeTable
	// as the code for character c.
	if (t->kind==leaf)
	{
		strcpy(codeTable[(int)t->ch], pref);
	}
	else
	// If t is not a leaf, then buildCode should call itself on the left and
	// right subtrees of t. The pref parameter for the call on the left subtree
	// should be pref with '0' added to the end. The pref parameter for the call
	// on the right subtree should be pref with '1' added to the end.
	{
		strcpy(temp,pref);
		buildCode(t->left, codeTable, strcat(temp,"0"));
		strcpy(temp,pref);
		buildCode(t->right, codeTable, strcat(temp,"1"));
	}
}

// writes a description of a given tree into a given open binary file.
void wrtieTreeBinary(BFILE* fb, Tree t)
{
	// To write a leaf, write a 1 bit followed by the
	// character stored at the leaf (8 bits)
	if (t->kind==leaf)
	{
		writeBit(fb, 1);
		writeByte(fb, t->ch);
	}
	else
	// To write a nonleaf, write a 0 bit followed by
	// the left subtree followed by the right subtree.
	{
		writeBit(fb, 0);
		wrtieTreeBinary(fb, t->left);
		wrtieTreeBinary(fb, t->right);
	}
}

// This function takes the array of character codes, a binary file
// that is opened for writing, and the name of the file to read.
void encodeInput(FILE *fp, BFILE* fb, char codeTable[][256])
{
	// reread the input file and write the code for
	// each character that it reads into the open binary file.
	while(1)
	{
		int c = fgetc(fp);
		if(feof(fp))break;
		char codeTemp[256];
		strcpy(codeTemp,codeTable[c]);
		for (int j = 0; j < strlen(codeTemp); j++)
		{
			if (codeTemp[j] == '0')
			{
				writeBit(fb, 0);
			}
			else
			{
				writeBit(fb, 1);
			}
		}
	}
}


int main(int argc, char *argv[])
{
	char codeTable[256][256];

	if (argc<3)
	{
		printf("ERROR, Not enough parameters...\n");
		return -1;
	}

	// sets the trace level to 1 if the command line contains -t
	tracelevel=0;
	if ((argv[1][0]=='-') && (argv[1][1]=='t'))
	{
		tracelevel=1;
	}

	// read the input
	FILE *fp = fopen(argv[1+tracelevel], "r");
	if (fp == NULL)
	{
		printf("ERROR, original file can't be found...\n");
		return -2;
	}

	// Create an array of 256 integers in main to store the frequency counts
	Frequency table[NUMBER_OF_CHARS];
	computeFrequency(fp, table);

	// if tracing is turned on, show the frequency counts
	if (tracelevel==1) ShowFrequenciesChars(table);

	// build Huffman tree
	Tree t = buildHuffmanTree(table);

    // if tracing is turned on, shows the Huffman tree.
	if (tracelevel==1) ShowHuffmanTree(t);

	// build code table
	char pref[256];
	strcpy(pref,"");
	for (int i = 0; i < 256; i++)
	{
		strcpy(codeTable[i],"");
	}
	buildCode(t, codeTable, pref);

	// if tracing is turned on, show the show hufferman code.
	if (tracelevel==1) ShowHuffmanCode(codeTable);

	BFILE *fb = openBinaryFileWrite(argv[2+tracelevel]);
	if (fb == NULL)
	{
		printf("ERROR, can't open target file...\n");
		return -3;
	}
	wrtieTreeBinary(fb, t);

	// use Huffman code to encode input
	fseek(fp,0,SEEK_SET);
	encodeInput(fp, fb, codeTable);

	closeBinaryFileWrite(fb);
	fclose(fp);
	printf("Successful !!\n");
	return 0;
}

