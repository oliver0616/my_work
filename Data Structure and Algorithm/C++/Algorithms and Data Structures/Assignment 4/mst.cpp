// This program for Kruskal's algorithm to find Minimum Spanning Tree
// of a given connected, undirected and weighted graph

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib.h>
#include "equiv.h"			// Use the equivalence relation manager
							// from the assignment 3

const int maxEdges = 100;	// assume that there are no more than 100 edges

// a structure to represent a weighted edge in graph
struct Edge
{
	int vertex1, vertex2, weight;
};

// a structure to represent a connected, undirected and weighted graph
struct Graph
{
	int numVertices;		// the number of vertices in the graph
	int numEdges;       	// the number of edges in the graph
	int psEdges;        	// the physical size of that array of edges
	struct Edge* edge;  	// an array of Edges that holds the edges
};

// constructor NewGraph(nv) that yields a graph with nv vertices and no edges
// and this constructor will create the array of edges.
struct Graph* newGraph(int nv)
{
	// allocate the memory buffer for Graph pointer g
	struct Graph* g = (struct Graph*) malloc( sizeof(struct Graph) );

	g->numVertices = nv;
	g->numEdges = 0;

	// assume that the max of edges are no more than maxEdges
	g->psEdges = maxEdges*sizeof(struct Edge);

	// allocate the memory buffer for the array of Edges
	g->edge = (struct Edge*) malloc( g->psEdges );

	return g;
}

// insertEdge(u, v, w, g) inserts an edge of weight w between vertices
// u and v into graph g.
//
// If there is not enough room in g to add the edge, then
// insertEdge does nothing.
void insertEdge(int u, int v, int w, struct Graph* g)
{
	if (g->numEdges<maxEdges) {
		g->edge[g->numEdges].vertex1 = u;
		g->edge[g->numEdges].vertex2 = v;
		g->edge[g->numEdges].weight = w;
		g->numEdges++;
	}
}

// readGraph() that takes no parameters and reads a graph from
// the standard input. It will return the graph.
//
// The input starts with a line that tells how many vertices the graph has.
// In general, if there are n vertices, then they are numbered 1, ¡K, n.
// Following the first line are the edges, one per line. Each edge line has
// three integers that includes two vertices and one weight number.
// The end of the input is signaled by a line that contains just a 0.
struct Graph* readGraph()
{
	int u, v, w;
	struct Graph* g;

	scanf("%d", &u);			// how many vertices the graph has
	scanf("\n");
	g = newGraph(u);
	while (u>0)					// u=0 is the end of file
	{
		scanf("%d", &u);    	// first vertex number
		if (u>0)
		{
			scanf("%d", &v);	// second vertex number
			scanf("%d", &w);    // weight number
			scanf("\n");
			insertEdge(u,v,w,g);
		}
	}
	return g;
}

// writeGraph(g) that writes a description of graph g on the standard output.
void writeGraph(struct Graph* g)
{
	int i;
	for(i=0;i<g->numEdges;i++)
	{
		printf("%d   %d        %2d\n",g->edge[i].vertex1,g->edge[i].vertex2,
				g->edge[i].weight);
	}
}

// compareEdges takes two parameters, which will be pointers to particular
// members of the array when qsort calls it. compareEdges(A, B) will return
// a negative number if *A should come before *B in the sorted array,
// a positive number if *A should come after *B in the sorted array.
int compareEdges(const void* a, const void* b)
{
	struct Edge* A = (struct Edge*)a;
	struct Edge* B = (struct Edge*)b;

	return A->weight - B->weight;
}

// sortEdges(g) that sorts the array of edges in graph g.
void sortEdges(struct Graph* g)
{
	// Use C library function qsort to sort the array of edges in graph g.
	qsort(g->edge, g->numEdges, sizeof(g->edge[0]), compareEdges);
}

// minimalSpanningTree(g) that take a graph g as a parameter and
// return a minimal spanning tree of K (also of type graph).
//
// uses Kruskal's algorithm to compute a minimal spanning tree.
// Create a new graph K without any edges.
struct Graph* minimalSpanningTree(struct Graph* g)
{
	struct Graph* K;
	int en=0;
	ER R;

	K = newGraph(g->numVertices);
	sortEdges(g);

	// For two vertices u and v, say that u~v just when there is
	// a path between u and v. Then ~ is an equivalence relation.
	// Use the equivalence relation manager from the assignment 3
	// to keep track of the equivalence classes of ~.
	R=newER(g->numVertices);
	while (en < g->numEdges-1)
	{
		// if u and v are not in the same equivalence class,
		// adding an edge between u and v into graph K, tell
		// the equivalence relation manager to merge u and v.
		if (!(equivalent(R,g->edge[en].vertex1,g->edge[en].vertex2)))
		{
			insertEdge(g->edge[en].vertex1,g->edge[en].vertex2,
						g->edge[en].weight,K);
			merge(R,g->edge[en].vertex1,g->edge[en].vertex2);
		}
		en++;
	}
	return K;
}

// sumWeight(K) compute the total weight of a graph by adding up
// the weights of the edges.
// It return the weight, and not write anything.
int sumWeight(struct Graph *K)
{
	int i,sw=0;

	for(i=0; i<K->numEdges; i++)
	{
		sw+=K->edge[i].weight;
	}
	return sw;
}

int main(int argc, char** argv)
{
	struct Graph *g,*K;

	g = readGraph();
	printf("Input graph:\n\n");
	printf("There are %d vertices and %d edges\n\n",g->numVertices,g->numEdges);
	printf("vertices    weight\n");
	writeGraph(g);
	K=minimalSpanningTree(g);
	printf("\n\n");
	printf("Minimal spanning tree:\n\n");
	printf("There are %d vertices and %d edges\n\n",g->numVertices,g->numEdges);
	printf("vertices    weight\n");
	writeGraph(K);
	printf("The total weight of spanning tree is %d\n",sumWeight(K));
}
