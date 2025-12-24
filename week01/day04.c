
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "basic_op.h"
int main() {
	int a[4] = { 4,1,2,3 };
	int b[6] = { 6,10,20,30,40,50 };
	int c[5] = { 5,100,200,300,400 };
	int* arr[3] = { a,b,c };
	printf("size: %d \n", sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		int* arrarr = arr[i];
		printf("size: %d \n", sizeof(arrarr[0]));
		printf("size: %d \n", sizeof(arrarr));
		for (int j = 0; j < sizeof(arrarr) / sizeof(arrarr[0]); j++)
		{
			printf("%d ",arrarr[j]);
		}
		printf ("\n");
	}
	return 0;
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE(a) (sizeof(a) / sizeof((a)[0]))

int dynamic_ary_print(int** arr, int size);
int main(void) {
	int a[4] = { 4, 1, 2, 3 };
	int b[6] = { 6, 10, 20, 30, 40, 50 };
	int c[5] = { 5, 100, 200, 300, 400 };
	int* arr[3] = { a, b, c };
	dynamic_ary_print(arr, SIZE(arr));
	return 0;
}

int dynamic_ary_print(int** arr, int size) {
	int* p = NULL;

	for (int i = 0; i < size; i++) {
		p = arr[i];
		for (int j = 1; j < p[0]; j++) {
			printf("%d ", p[j]);
		}
		printf("\n");
	}
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE(a) (sizeof(a) / sizeof((a)[0]))

int main(void) {
	char ch1, ch2;
	(void)scanf(" %c %c",&ch1,&ch2);
	printf("[%c%c]", ch1, ch2);
	return 0;

}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE(a) (sizeof(a) / sizeof((a)[0]))

int main(void) {
	char ch1[30], ch2[30];
	ch1[0] = 's';

	printf("[%s%s]", ch1, ch2);
	return 0;

}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define size_ary(a) (sizeof(a) / sizeof((a)[0]))

int main(void) {
	char str[30];
	my_gets(str, size_ary(str));
	printf("%s", str);
	return 0;
}
int my_gets(char* str, int size) {
	int i = 0;
	char ch="f";
	while (ch!='\n' && i<size) {
		ch = getchar();
		str[i] = ch;
		i++;
	}
	str[i-1] = '\0';
	
	
	return 1;
}

#endif


#if 00
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define size_ary(a) (sizeof(a) / sizeof((a)[0]))
int print_ary(char* str) {
	printf("%s", str);
	return 1;
}

char* to_upper(char* name) {
	int i = 0;
	while ('\0' != name[i]) {
		if (name[i] >= 'a' && name[i] <= 'z') {
			name[i] = name[i] - 'a' + 'A';
		}
		i++;
	}
	return name;
}

int main(void) {
	char name[40] ="Tom & Jerry!";
	
	print_ary(to_upper(name));
	
	return 0;
}

#endif
//숙제 도약
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N=0;
	int count = 0;
	(void)scanf("%d", &N);
	int arr[100];
	for (int i = 0; i < N; i++)
	{
		(void)scanf("%d", arr[i]);
	}
	for (int i = 0; i < N-2; i++)
	{
		int first = arr[i];
		for (int j = i+1; j < N-1; j++)
		{
			int second = arr[j];
			for (int k = 0; k < N; k++)
			{
				int third = arr[k];
			}
		}
	}
}

#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int N = 0;
	int k = 0;
	int n = 0;
	return 0;
}

#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	printf("%d", sizeof("banana"));
	return 0;
}

#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>




int main(void) {
	const char * dessert = "banana"; //내용만 변경 금지
	char const* dessert1_1 = "banana";

	char* const  dessert2 = "banana"; //주소만 변경 금지
	char const dessert3 = "banana";//??
	//dessert = "a"; xxxx
	char * const dessert4 = "apple";
	dessert = dessert2;
	printf("%s", dessert2);
	return 0;
}

#endif
