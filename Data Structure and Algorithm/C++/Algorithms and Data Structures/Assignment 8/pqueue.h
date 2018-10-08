// CSCI 2530
// Assignment: 5
// Author:     Huan-Yun Chen
// File:       pqueue.h
// Tab stops:  4

#include <cstdio>
#include "tree.h"

// These #ifndef and #define lines make it so that, if this file is
// read more than once by the compiler, its body is skipped on all
// but the first time it is read.

#ifndef PQUEUE_H
#define PQUEUE_H

// define PQItemType for the type of an item and 
// PQPriorityType for the type of a priority
// to write the entire implementation of priority queues 

typedef Tree PQItemType;
typedef int PQPriorityType;

// define a structure type, PQCell, that is used as a cell
// in a linked list. It holds an item, a priority, and
// a pointer to the next cell in the list.
struct PQCell
{
	PQItemType item;
	PQPriorityType priority;
	PQCell* next;

	PQCell(PQItemType i, PQPriorityType pri, PQCell* n)
	{
		item = i;
		priority = pri;
		next = n;
	}
};


struct PriorityQueue
{
	PQCell* queue;

	PriorityQueue()
	{
		queue = NULL;
	}
};

// Public functions

bool isEmpty(const PriorityQueue& q);
void insert(PQItemType item, PQPriorityType pri, PriorityQueue& q);
void remove(PQItemType& item, PQPriorityType& pri, PriorityQueue& q);

// The following is advertised here solely for debugging.  These must
// only be used for debugging.

typedef void (ItemPrinter)(PQItemType);
typedef void (PriorityPrinter)(PQPriorityType);

void printPriorityQueue(const PriorityQueue& q, ItemPrinter pi, PriorityPrinter pp);

#endif
