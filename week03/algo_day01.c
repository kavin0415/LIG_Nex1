#if 0
#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>	
#include <stdlib.h>

int cnt = 0;
void test(int sum) {
	int arr[10];
	printf("%d %d\n", sum, ++cnt);
	test(sum + cnt);
}
int N = 4;//123443442344344
void test2(int L) {
	printf("L = %d\n", L);
	test2(L + 1);
}
void test3(int L) {
	if (L > N) {
		return;
	}
	printf("L = %d\n", L);
	test3(L + 1);
}
void test4(int L) {
	if (L > N) {
		return;
	}
	printf("%d ", L);
	test4(L + 1);
	printf("%d ", L);
}
void test5(int L) {
	if (L > N) {
		return;
	}
	if (L % 2 == 1) printf("%d ", L);

	test5(L + 1);
	if (L % 2 == 0) printf("%d ", L);
}
void test7(int L) {
	if (L > N) return;
	for (int i = 0; i < L; i++)	printf("%d ", i+1);
	printf("\n");
	test7(L + 1);
}
void test8(int L) {
	if (L > N) return;
	printf("%d ", L);
	test8(L + 1);
	test8(L + 1);
}
int main(void) {
	test8(1);
	return 0;
}
#endif