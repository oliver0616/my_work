#include "equiv.h"
#include <cstdio>
using namespace std;
int main(int argc, char** argv)
{
	int n;
	ER R;
	bool f;
	R=newER(7);
	printf("ER R = newER(7)\n");
	showER(R,7);
	merge(R,1,5);
	printf("merge(R,1,5)\n");
	showER(R,7);
	merge(R,2,7);
	printf("merge(R,2,7)\n");
	showER(R,7);
	printf("equivalent(R,1,5) yields ");
	if (equivalent(R,1,5)) printf("true\n");
	  else printf("false\n");
	printf("equivalent(R,1,7) yields ");
	if (equivalent(R,1,7)) printf("true\n");
	  else printf("false\n");
	merge(R,5,7);
	printf("merge(R,5,7)\n");
	showER(R,7);
	scanf("%i",&n);
}