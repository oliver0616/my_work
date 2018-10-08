// CSCI 2530
// Assignment: programming assignment 6
// Author:     Huan-Yun Chen
// File:       dijkstra.cpp
// Tab stops:  4

// **Say what this program does here.  (replace this comment)**


#include <cstdio>
#include <iostream>
#include "pqueue.h"
using namespace std;

// type Edge is used for a cell in an adjacency list.

struct Edge
{
	int u;              // vertex number
	PQPriorityType w;   // weight
	Edge* next;         // point to the next Edge in the linked list

	// the constructor for struct Edge
	Edge(int n, double weight, Edge* e)
	{
		u = n;
		w = weight;
		next = e;
	}

	Edge()
	{
		u = 0;
		w = 0;
		next = NULL;
	}
};


struct Vertex
{
	Edge* adjacency; // a pointer to a linked list of edges listing all edges
	int sd;          // a number indicating shortest distance from the start vertex
	int u;           // a vertex number, the shortest path from v to u,
					 // if the shortest path is not known, u is -1.

	// the constructor for struct Vertex with no parameters
	Vertex()
	{
		adjacency = NULL;
		sd = -1;
		u = -1;
	}
};

struct Graph
{
	int numVertices;   // the number of vertices
	int numEdges;       // the number of edges
	Vertex* v;          // an array of vertices

	// the constructor for struct Graph with a integer parameter
	Graph(int n)
	{
		numVertices = n;   // the number of Vertices
		numEdges = 0;       // the number of Edges
		v = new Vertex[n];  // allocate an array for the Vertices
	}
};

//==============================================================================

// readGraph() that takes no parameters and reads a graph from the standard input.

void readGraph(Graph* g)
{
	PQPriorityType weight;
	int v1, v2;

	while (true)
	{
		cin >> v1;

		if (v1 == 0)
		{
			break;
		}

		cin >> v2;
		cin >> weight;

		if (g->v[v1].adjacency == NULL)
		{
			Edge* tempList = new Edge(v2, weight, NULL);
			g->v[v1].adjacency = tempList;
		}
		else
		{
			Edge* tempList = new Edge(v2, weight, g->v[v1].adjacency);
			g->v[v1].adjacency = tempList;
		}

		if (g->v[v2].adjacency == NULL)
		{
			Edge* tempList = new Edge(v1, weight, NULL);
			g->v[v2].adjacency = tempList;
		}
		else
		{
			Edge* tempList = new Edge(v1, weight, g->v[v2].adjacency);
			g->v[v2].adjacency = tempList;
		}
		g->numEdges++;
	}
}

// Prints the values of Graph g.

void printGraph(Graph* g)
{
	int i = 0;
	cout << "There are " << g->numVertices - 1 << " vertices and "
		 << g->numEdges << " edges." << endl;
	cout << "The edges are as follows." << endl << endl;

	while (i < g->numVertices)
	{
		if (g->v[i].adjacency == NULL)
		{
			i++;
		}
		else
		{
			if (i < g->v[i].adjacency->u)
			{
				cout << "(" << i << ",";
				cout << g->v[i].adjacency->u << ") ";
				cout << "weight " << g->v[i].adjacency->w << endl;
			}
			g->v[i].adjacency = g->v[i].adjacency->next;
		}
	}
}
//==============================================================================

void signal(Graph g, Vertex v,PriorityQueue q)
{

}

void aEvent()
{

}

int main(int argc, char** argv)
{
	int numVertices, x, first, last;
	PriorityQueue q;
	x = 0;
	cin >> numVertices;
	numVertices = numVertices + 1;
	Graph* g = new Graph(numVertices);
	readGraph(g);
	cin >> first;
	cin >> last;
	printGraph(g);
}


