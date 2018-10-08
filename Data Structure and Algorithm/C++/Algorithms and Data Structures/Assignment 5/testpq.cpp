// CSCI 2530
// Assignment: 5
// Author:     Huan-Yun Chen
// File:       testpq.cpp
// Tab stops:  4

#include "pqueue.h"
#include <cstdio>
using namespace std;

typedef const char* CSTRING;

  void printString(CSTRING s)
  {
	printf("%s", s);
  }

  void printDouble(double x)
  {
	printf("%lf", x);
  }

int main(int argc, char** argv)
{

PQItemType temp1;
PQPriorityType temp2;
PriorityQueue q;
int n;
if(isEmpty(q)) printf("true\n");
else printf("false\n");
insert("Oliver",2,q);
insert("Paul",1,q);
insert("Zoe",3,q);
printPriorityQueue(q,printString, printDouble);
if(isEmpty(q)) printf("true\n");
else printf("false\n");
remove(temp1,temp2,q);
if(isEmpty(q)) printf("true\n");
else printf("false\n");
scanf("%i",&n);
}