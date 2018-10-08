#include <stdio.h>
#include <cctype>
#include "tree.h"
#include "trace.h"

// if tracing is turned on, shows the frequencies of all characters
// that occur at least once in a clear and readable format.
void ShowFrequenciesChars (Frequency *table)
{
	printf("The character frequencies are:\n");
	for(int i = 0; i < NUMBER_OF_CHARS; i++)
	{
		if (table[i].v>0)
		{
			if (isprint(table[i].c))
			{
				printf("%c %d\n",table[i].c,table[i].v);
			}
			else
			{
				printf("\\%d %d\n",table[i].c,table[i].v);
			}
		}
	}
}

// This function will print a tree with the given indent.  It
// recursively visits each node in the tree and prints the information
// contained in the node at the correct indent.
void TreePrintIndent (Tree t, int depth, int indent, int sd)
{
	if (t != NULL)
	{
		if (t->kind == leaf)
		{
			if (sd==1)
			{
				printf("(");
			}
			if (isprint(t->ch))
			{
				printf("%c",t->ch);
			}
			else
			{
				printf("\\%d",t->ch);
			}
			if (sd==1)
			{
				printf(",");
			}
			if ((sd==2) && (t->ch!='\0'))
			{
				printf(")");
			}
		}
		else
		{
			if (sd==1)
			{
				printf("(");
			}
			if (sd==2)
			{
				printf(")");
			}
			TreePrintIndent(t->left , depth+1, indent+2, 1);
			TreePrintIndent(t->right, depth+1, indent+2, 2);
		}
	}
}

// if tracing is turned on, shows the Huffman tree.
void ShowHuffmanTree(Tree t)
{
	printf("\nThe Huffman tree is as follows.\n");
	TreePrintIndent(t, 0, 0, 0);
	printf("\n");
}

// if tracing is turned on, show the Huffman code.
void ShowHuffmanCode(char codeTable[][256])
{
	printf("\nA Huffman code is as follows.\n");
	for (int i = 0; i < 256; i++)
	{
		if (!codeTable[i][0]=='\0')
		{
			printf("%c %s\n",i,codeTable[i]);
		}
	}
    printf("\n");
}


