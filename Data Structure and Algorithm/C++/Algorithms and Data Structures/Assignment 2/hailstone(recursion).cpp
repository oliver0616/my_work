// CSCI 2530
// Assignment: programming assignment 2
// Author:     Huan-Yun Chen
// File:       hailstone.cpp
// Tab stops:  4

// This program help us to calculate out the hailstone sequence and to find the longest
// sequence and its start number.
// int next(int n) : help to figure number is even or odd
// void sequence(int n) : find the number of the sequence and list them out
// int length(int n) : find the length of the sequence
// void maxNumRecur(int n, int *maxp): calculate out the maximum number
// int maxNum(int n): return the maximum number
// void maxLengthRecur(int n, int *ct, int *max): calculate maximum length from 1 to n
// int maxLength(int n): return the maximum length from 1 to n
// void maxLenNumRecur(int n, int *ct, int *max, int *maxNum): calculate the start number
// of the maximum length from 1 to n
// int maxLenNum(int n): return start number of the maximum length from 1 to n


#include <cstdio>
using namespace std;

// Describtion : help to figure number is even or odd
// Parameters : int n -> number of the sequence
// Return : the result of the calculation
int next(int n)
{
		if (n%2 == 0)  				   //when number is even
		{
			n = n/2;
		}
		else           				   //when number is odd
		{
			n = 3*n+1;
		}
		return n;
}

// Describtion: List out all the hailstone sequences
// Parameters:  int n -> number of the sequence
// Return: none
void sequence(int n)
{
	if (n>1)
	{
		n=next(n);
		printf("%i ",n);
		sequence(n);
	}
	else if (n == 1)
	{
		printf("%i ",n);
	}

}

// Describtion: figure the length of the hailstone sequence
// Parameters: int n -> number of the sequence
// Return: the length of the hailstone sequence
int length(int n)
{
	if (n>1)
	{
		return 1+length(next(n));
	}
	else if (n == 1)
	{
	   return 1;
	}

}

// Describtion: calculate out the maximum number in a sequence
// Parameters: *maxp -> the value of max in maxNum
//			   int n -> number of the sequence
// Return: the resualt of the calculation
void maxNumRecur(int n, int *maxp)
{
	if (n>1)
	{
		n=next(n);
		if(n>*maxp)
		{
			*maxp=n;
		}
		maxNumRecur(n, maxp);
	}
}

// Describtion: to find the maimum value in a hailstone sequence
// Parameters: int n -> number of the sequence
//			   int max -> the comparison with n
// Return:maximum number in a sequence
int maxNum(int n)   				   //number of the sequence
{
	int max=n;

	maxNumRecur(n, &max);
	return max;
}

// Describtion: calculate out the maximum length from 1 to n
// Parameters:  int n -> number of the sequence
//				int *ct -> counter that start from 1 to n
//				int *max -> maximum length in a sequence
//				int j -> the length of the sequence from 1 to n
// Return: the maximum length from 1 to n
void maxLengthRecur(int n, int *ct, int *max)
{
	int j;
	if (*ct<=n)
	{
		j=length(*ct);
		if (j> *max)
		{
			*max = j;
		}
		*ct=*ct+1;
		maxLengthRecur(n, ct, max);
	}

}

// Describtion: find the maximum length from 1 to n
// Parameters: int n -> number of the sequence
//			   int *ct -> counter that start from 1 to n
//			   int *max -> maximum length in a sequence
// Return: the maximum length from 1 to n
int maxLength(int n)
{
	int ct=1;
	int max=1;

	maxLengthRecur(n,&ct,&max);
	return max;
}

// Describtion: calculate the start number of the maximum length
// Parameters: int n -> number of the sequence
//			   int *ct -> counter that start from 1 to n
//			   int *max -> maximum length in a sequence
//			   int *maxNum -> the maximum length start number
//    		   int j -> the length of the sequence from 1 to n
// Return: maximum length start number
void maxLenNumRecur(int n, int *ct, int *max, int *maxNum)
{
	int j;

	if (*ct<=n)
	{
		j=length(*ct);
		if (j> *max)
		{
			*max = j;
			*maxNum = *ct;
		}
		*ct=*ct+1;
		maxLenNumRecur(n, ct, max, maxNum);
	}
}

// Describtion: find the start number of the maximum length
// Parameters: int n -> number of the sequence
//			   int *ct -> counter that start from 1 to n
//			   int *max -> maximum length in a sequence
//			   int *maxNum -> the maximum length start number
// Return: maximum length start number
int maxLenNum(int n)
{
	int max=1;
	int maxNum=1;
	int ct=1;

	maxLenNumRecur(n,&ct,&max,&maxNum);
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
