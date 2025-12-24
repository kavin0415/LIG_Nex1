#include<stdio.h>	
#define MAX 10;
typedef int* IP;
#ifndef __VAR_A__
#define __VAR_A__
int a = 0;
#endif
#ifndef __STRUCT_STUDENT__
#define __STRUCT_STUDENT__
struct student {
	char name[20];
	int score;
};
#endif