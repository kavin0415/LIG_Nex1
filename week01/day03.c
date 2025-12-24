#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int score[5];
	int size = sizeof(score) / sizeof(score[0]);
	for (int i = 0; i < size); i++)
	{
		scanf("%d", &score[i]);
	}
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += score[i];
	}
	float mean = (float)sum / size;
	printf("%f", mean);
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int (*p)[4] = a;
	int* x = (int*)a;
	//printf("%X %X",a,a+1);
	printf("%d\n", a[0][0] + a[1][1] + a[2][2]);

	printf("%d\n", *p[0] + *p[1] + *p[2]);
	printf("%d\n", *x + *x + *x);
	return 0;
}
#endif
// 여기까지 내가 짠거 이후 외출 기문이형이 보내줌	
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str1[80] = "tiger";
	char str2[80];

	strcpy(str1, "cat");
	strcpy(str2, str1);

	printf("%s %s\n", str1, str2);

	gets(str1);
	puts(str1);

	return 0;
}

#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	double avgdb = 5.0;
	int avgin = 5;
	char avgch = 5;

	double* pdb = &avgdb;
	int* pin = &avgin;
	char* pch = &avgch;

	printf("%d, %d, %d", sizeof(pdb), sizeof(pin), sizeof(pch));

	return 0;
}

#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(void) {
	int a = 10, b = 20;

	printf("%d, %d\n", a, b);

	swap(&a, &b);

	printf("%d, %d\n", a, b);

	return 0;
}

#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	int a = 10;
	int* p = &a;
	int** pp = &p;

	printf("%p, %p", p, p[0]);

	return 0;
}

#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int sum(int a, int b) {
	return a + b;
}

int main(void) {
	int arr[3][4] = { 0 };

	printf("%p, %p, %d\n", arr, *arr, **arr);
	printf("%p, %p\n", arr + 1, *arr + 1);
	printf("%p, %p, %p\n", sum, *sum, **sum);

	int (*p) (int, int) = sum;

	int a = 10, b = 20;

	int sum = p(10, 20);
	printf("%d", sum);

	return 0;
}

#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char* (*func(void))[10] {
	char* ans[10] = { "tiger", "apple" };
	return ans;
}

int main(void) {
	char* (*(*var)(void))[10] = func;
	printf("%s", var()[0]);
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "basic_op.h"
int main() {
	int arr[5] = { 0 };
	scanf_ary(arr, 5);
	print_ary(arr, 5);
	printf("max %d", findmax_ary(arr, 5));
	printf("min %d", findmin_ary(arr, 5));
	printf("sum %d", sum_ary(arr, 5));
	printf("sum %f", avg_ary(arr, 5));
	return 0;
}


#endif