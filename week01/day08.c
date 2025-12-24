#if 0
#include<stdio.h>	
#include<stdlib.h>	
typedef union pixelcolor {

}tPColor;
int main(void) {
	tPColor dot1 = { 0 };
	tPColor dot2 = { 0 };

	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	
#include<stdlib.h>	
unsigned int readKey() {
	return 95;
}
enum{UP=95,DOWN =102,LEFT= 115,RIGHT= 120};
int main(void) {
	
	return 0;
}
#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>	
#include<stdlib.h>	
enum {KOR=0,ENG,MAT};
int main(void) {
	int scores[3];
	int tot = 0;
	tot = scores[KOR] + scores[ENG] + scores[MAT];
	if (scores[KOR] > 80) {

	}
}

#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // memset
#include <stdlib.h>

int printAry(char(*ary)[10], int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%s ", ary[i]);
	}
	printf("\n");
}

typedef char CH10[][10];
typedef int(*FNCH10)(char(*ary)[10], int size);

int main(void) {
	CH10 fruit = { "apple", "melon", "cherry" };
	FNCH10 fn;
	fn = printAry;
	fn(fruit, sizeof(fruit) / sizeof(fruit[0]));
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // memset
#include <stdlib.h>
int main(void) {
	int a;
	int score[3][4] = { 11,10,9,8,7,6,5,4,3,2,1 };;
	int x = (int)score;
	printf("%d ", ((int(*)[4])x)[0][0] + 1);
	printf("%d ", ((int*)x)[5]);
	printf("%d ", (((int(*)[2][3])x)+1)[0][0][0]);
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // memset
#include <stdlib.h>
int main(void) {
	int (*a)[4];
	char* (*b)[2];
	int (*c)(void);
	a = (int(*)[4])0x1000;
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // memset
#include <stdlib.h>
#include "include\temp.h"
int main(void) {
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	print_ary(a, 10);
	return 0;
}


#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // memset
#include <stdlib.h>
#define Add(a,b,c) Add##a((b),(c))
int Add1(int a, int b) {
	return a + b;
}
int Add2(int a, int b) {
	return 1000 + a + b;
}
int Add3(int a, int b) {
	return 1000 + a + b;
}
int main(void) {
	int x = 1;
	printf("%d\n", Add(1, 4, 6));
	printf("%d\n", Add(3, 2, 5));
	printf("%d\n", Add(x, 4, 6));

	return 0;
}


#endif