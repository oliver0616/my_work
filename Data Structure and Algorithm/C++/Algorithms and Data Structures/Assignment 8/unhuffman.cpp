// CSCI 2530
// Assignment: programming assignment 8
// Author:     Huan-Yun Chen
// File:       unhuffman.cpp
// Tab stops:  4
// **Implementation of the data decompression**
//---------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "tree.h"
#include "trace.h"
#include "binary.h"

//---------------------------------------------------------------------------

// reads a tree whose description is in a given open BFILE* file,
// and returns the tree.
Tree readTreeBinary(BFILE* fb)
{
	// To read a tree, start by reading a bit.
	int isLeaf = readBit(fb);
	// If the bit is a 1, you are looking at a leaf.
	if (isLeaf==1)
	{
		// Read the character (a byte) and build a leaf holding that character.
		char ch = readByte(fb);
		return new Node(ch);
	}
	else
	// If the bit is a 0, then you are looking at a nonleaf.
	{
		// Read the left subtree then the right subtree.
		Tree left = readTreeBinary(fb);
		Tree right = readTreeBinary(fb);
		return new Node(left, right);
	}
}

// This function takes the Huffman tree and an open binary file for reading.
void expandOutput(FILE *fp, BFILE *fb, Tree t)
{
	while(1)
	{
		Tree tt=t;
		// As read each bit, move down the tree.
		// When hit a leaf, that is the answer.
		while (tt->kind==nonleaf)
		{
			int bit = readBit(fb);
			if (bit==1)
			{
				tt=tt->right;
			}
			else if (bit==0)
			{
				tt=tt->left;
			} else
			{
                return;
            }
		}
		// There is no bit for a leaf. So when reading the code,
		// only read a bit at a nonleaf in the tree
		fputc(tt->ch, fp);
	}

}

int main (int argc, char *argv[])
{
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

	FILE *fp = fopen(argv[2+tracelevel], "w");
	if (fp == NULL)
	{
		printf("ERROR, original file can't be found...\n");
		return -1;
	}

	BFILE *fb = openBinaryFileRead(argv[1+tracelevel]);
	if (fb == NULL)
	{
		printf("ERROR, can't open target file...\n");
		return -2;
	}

	// read in Huffman trie from input stream
	Tree t=readTreeBinary(fb);

	// if tracing is turned on, writes the tree to the standard output for debugging.
	if (tracelevel==1)
	{
		ShowHuffmanTree(t);
	}

	// expand Huffman-encoded input and write to standard output
	expandOutput(fp,fb,t);

	closeBinaryFileWrite(fb);
	fclose(fp);

	printf("Successful !!\n");
	return 0;
}