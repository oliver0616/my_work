// CSCI 2530
// Assignment: programming assignment 7
// Author:     Huan-Yun Chen
// File:       lis.cpp
// Tab stops:  4
// **Using dynamic programming to Compute Longest Increasing Sublists**
//---------------------------------------------------------------------------

#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int maxNumbers = 100;
const int maxName = 100;

struct mountain
{
	char* name;
	int elevation;

	mountain()
	{
		elevation = 0;
	}
};

struct List
{
	int item;
	List* next;

	List(List* nxt, int it)
	{
		next = nxt;
		item = it;
	}
};

// Store the mountain names and elevations in an array of structures
struct bookMountains
{
	int numMountains;
	mountain* allMountains;
	List* bis[maxNumbers];  // Keep one array of linked lists to store the bis's

	bookMountains(int nm, mountain* ma)
	{
		numMountains = nm;
		allMountains = ma;
	}
};

// create a mountain array and read data from the standard input.
bookMountains newMountain()
{
	mountain* n = new mountain[maxNumbers];
	int count = 0;
	int i;
	for(i = 0; i < maxNumbers; i++)
	{
		n[i].name = new char[maxName];

		// Each line contains a mountain name and an elevation.
		scanf("%s", n[i].name);
		scanf("%d", &n[i].elevation);

		// find end-of-file in program using feof(stdin)
		if(feof(stdin))
		{
			break;
		}

		// count how many mountains in file
		if (n[i].elevation != 0)
		{
			count++;
		}
	}

	bookMountains bm(count, n);
	return bm;
}

int positionS(bookMountains bm, int i, int count)
{
	int s = count;
	while(bm.bis[s] != NULL && bm.allMountains[bm.bis[s]->item].elevation > bm.allMountains[i].elevation)
	{
		s--;
	}
	return s+1;
}

// shows the mountains in the longest bis.
void printResult(bookMountains bm, int count)
{
	// the list is backwards, reverse it.
	List* l = NULL;
	while(bm.bis[count] != NULL)
	{
		l = new List(l, bm.bis[count]->item);
		bm.bis[count] = bm.bis[count] -> next;
	}

	// list the mountains to climb, in order,
	// giving each in a format similar to the input.
	for(List* ptr = l; ptr != NULL; ptr = ptr -> next)
	{
		printf("%-30s ",bm.allMountains[ptr->item].name);
		printf("%10d\n",bm.allMountains[ptr->item].elevation);
	}
}

int main(int argc, char** argv)
{
	int i, s;
	int count = 0;

	bookMountains bm = newMountain();
	for(i = 0; i < maxNumbers; i++)
	{
		// make all of the lists NULL
		bm.bis[i] = NULL;
	}

	for(i = 0; i < bm.numMountains; i++)
	{
		s = positionS(bm, i, count);

		// store each bis as a linked list backwards
		// and store the mountain indices, not the elevations
		bm.bis[s] = new List(bm.bis[s-1],i);

		//  compare the elevations, not the indices
		count = max(s, count);
	}
	printResult(bm, count);

	return 0;
}

