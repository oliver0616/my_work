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

// isEmpty(q) will return true if q is empty,
// false if q is not empty.
bool isEmpty(const PriorityQueue& q)
{
	return q.queue == NULL;
}

// Inserts item with the priority pri into priority queue q
void insert(PQItemType item, PQPriorityType pri, PriorityQueue& q)
{
	PQCell *newnode=new PQCell(item, pri, NULL);

	if (q.queue == NULL || pri < q.queue->priority)
	{
		newnode->next=q.queue;
		q.queue=newnode;
	}
	else
	{
		PQCell *prev=q.queue;
		while(prev->next!=NULL && prev->next->priority <= pri)
		{
			prev=prev->next;
		}
		newnode->next=prev->next;
        prev->next=newnode;
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





