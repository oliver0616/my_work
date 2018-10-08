// CSCI 2530
// Assignment: programming assignment 3
// Author:     Huan-Yun Chen
// File:       equiv.cpp
// Tab stops:  4
// **Implementation of an Equivalence Relation Manager**
//---------------------------------------------------------------------------
#include "equiv.h"
#include <cstdio>
using namespace std;
//---------------------------------------------------------------------------

// newER(int n) returns an array of n+1 integers.
// This array will be used to store the bosses.
// Requirement: n > 0.
ER newER(int n)
{
	//----------------------------------------------
	// Allocate an array of n+1 integers in the heap
	//----------------------------------------------
	ER R=new int[n+1];
	int x;

	//----------------------------------------------
	// Initialize the array so that each value is a
	// leader of its own group. That is,
	// each value is its own boss.
	//----------------------------------------------
	for(x=1; x<=n; x++)
	{
		R[x]=x;					// R[x] is x's boss
	}
	return R;
}

// This function merges the equivalence classes of x and y in R as follows.
// Requirement: have to call newER first, x > 0 and y >0.
void merge(ER R, int x, int y)
{
	//----------------------------------------------
	// find the leaders xl and yl of x and y
	//----------------------------------------------
	int xl=leader(R,x);
	int yl=leader(R,y);

	//----------------------------------------------
	//  If x¡ä and y¡ä are different
	//  then y¡ä becomes the new boss of x¡ä
	//----------------------------------------------
	if (xl!=yl)
	{
		R[xl]=yl;
	}
}

// Returns true if x and y are currently in the same
// equivalence class in equivalence relation R.
// Requirement: have to call newER first, x > 0 and y >0.
bool equivalent (ER R, int x, int y)
{
	//----------------------------------------------
	// They are in the same equivalence class
	// if they have the same leader.
	//----------------------------------------------
	if (leader(R,x)==leader(R,y))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//  Deallocates R
void destroyER(ER R)
{
	delete []R;
}

// Return the leader of x in equivalence relation R.
// To compute x's leader, just follow the bosses up to the leader.
// Requirement: have to call newER first, x > 0 and y >0.
int leader(ER R, int x)
{
	int r=x;

	//----------------------------------------------
	// find the leader by going to the boss,
	// then to the boss's boss, etc, until
	// hit a number that does not have a boss.
	//----------------------------------------------
	while(R[r] != r)
	{
		r = R[r];
    }
	return r;
}

//  Showes R
void showER(ER R, int n)
{
	int i,j;

	for(i=1; i<=n; i++)
	{
		printf("R[%i]=%i ",i,R[i]);
	}
	printf("\n");
}
