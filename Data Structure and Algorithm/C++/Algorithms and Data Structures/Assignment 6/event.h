// CSCI 2530
// Assignment: 6
// Author:     Huan-Yun Chen
// File:       event.h
// Tab stops:  4

#include <cstdio>

// These #ifndef and #define lines make it so that, if this file is
// read more than once by the compiler, its body is skipped on all
// but the first time it is read.

#ifndef EVENT_H
#define EVENT_H

struct Event
{
	double u;
	double v;
	double t;

	Event(double preivous, double next, double time)
	{
		u = preivous;
		v = next;
		t = time;
    }
};

#endif



