// CSCI 2530
// Assignment: programming assignment 5
// Author:     Huan-Yun Chen
// File:       pqueue.cpp
// Tab stops:  4
// **Implementation of a Priority Queue Manager**
//---------------------------------------------------------------------------
#include "pqueue.h"
#include <cstdio>
#include <iostream>
using namespace std;
//---------------------------------------------------------------------------

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

// isEmpty(q) will return true if q is empty,
// false if q is not empty.
bool isEmpty(const PriorityQueue& q)
{
	return q.queue == NULL;
}

// Inserts item with priority pri into the linked list pointed to by p
void insertCell(const PQItemType& item, PQPriorityType pri, PQCell*& p)
{
	if (p == NULL)
	{
		p = new PQCell(item, pri, NULL);
	}
	else if (pri <= p->priority)
	{
		p->next = new PQCell(item, pri, p->next);
	}
	else
	{
		insertCell(item, pri, p->next);
	}
}

// Inserts item with the priority pri into priority queue q
void insert(PQItemType item, PQPriorityType pri, PriorityQueue& q)
{
	if (q.queue == NULL || pri <= q.queue->priority)
	{
		q.queue = new PQCell(item, pri, q.queue);
	}
	else
	{
		insertCell(item, pri, q.queue);
	}
}

// Removes the item from the priority queue with the lowest priority.
void remove(PQItemType& item, PQPriorityType& pri, PriorityQueue& q)
{
	if (q.queue != NULL)
	{
		item = q.queue->item;
		pri = q.queue->priority;
		PriorityQueue priQTemp;
		priQTemp.queue = q.queue;
		q.queue = priQTemp.queue->next;
		delete priQTemp.queue;
	}
}

// Prints the priority queue q, in order from lowest priority to highest priority
void printPriorityQueue(const PriorityQueue& q, ItemPrinter pi, PriorityPrinter pp)
{
	PriorityQueue t;
	t.queue = q.queue;
	while (t.queue != NULL)
	{
		pi(t.queue->item);
		cout << "\t";
		pp(t.queue->priority);
		cout << endl;
		t.queue = t.queue->next;
	}
}





