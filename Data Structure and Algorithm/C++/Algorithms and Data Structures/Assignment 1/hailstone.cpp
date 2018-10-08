// CSCI 2530
// Assignment: programming assignment 1
// Author:     Huan-Yun Chen
// File:       ***
// Tab stops:  4

// This program help us to calculate out the hailstone sequence and to find the longest
// sequence and its start number, there are 6 functions and 1 main function.


#include <cstdio>
using namespace std;

// help to figure number is even or odd
int next(int n) 					   //number of the sequence
{
		if (n%2 == 0)  				   //when number is even
		{
			n = n/2;
		}
		else           				   //when number is odd
		{
			n = 3*n+1;
		}
		return n;     				   //return the answer
}
//find the number of the sequence and list them out
void sequence(int n)  				   //number of the sequence
{
	while(n!= 1)
	{
		n=next(n);
		printf("%i ",n);
	}
}
//find the length of the sequence
int length(int n)   				   //number of the sequence
{
	int count=1;    				   //counter
	while(n!= 1)
	{
		n=next(n);
		count++;
	}
	return count;
}
//find the maximum number in a sequence
int maxNum(int n)   				   //number of the sequence
{
	int max=n;
	while(n!=1)
	{
		n=next(n);
		if(n>max)             		   // when there are larger n, max get
		{                              // replace by the largest number
			max=n;
		}

	}
	return max;
}
//find the longest length from 1 to n
int maxLength(int n)  				   //number of the sequence
{
	int max = 1;
	int j;
	for (int i = 1; i <= n; i++)
	{
		j=length(i);
		if (j> max)
		{
			max = j;
		}
	}
	return max;
}
//find the start number of the longest length
int maxLenNum(int n)  				   //number of the sequence
{
	int max = 1;
	int j;
	int maxNum=1;
	for (int i = 1; i <= n; i++)
	{
		j=length(i);
		if (j> max)
		{
			max = j;
			maxNum = i;
		}
	}
	return maxNum;
}


int main(int argc, char** argv)
{
	int n;		  					   //variable user put in, number of the sequence

	printf("What should i start with?");
	scanf("%i",&n);
	printf("The hailstone sequence starting at %i is:\n",n);
	printf("%i ",n);
	sequence(n);
	printf("\nThe length of the sequence is %i",length(n));
	printf("\nThe largest number in the sequence is %i", maxNum(n));
	printf("\nThe longest hailstone sequence starting with a number up to %i has length %i"
	,n,maxLength(n));
	printf("\nThe longest hailstone sequence starting with a number up to %i begins with %i"
	,n,maxLenNum(n));

	scanf("%i",&n);  // to pause the prgram
}


