#if 0
#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>

int cnt = 0;
int N = 4;
void test(int L) {
	if (L > N) return;
	printf("%d ", L);
	test(L + 1);
	test(L + 1);
}
int main(void) {
	test(1);
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>
int N = 3;
void test(int L,int start, int end) {
	if (L > N) {
		return;
	}
	for (int i = start; i < end; i++)
	{
		test(L+1,i + 1, end + 1);
	}
}
int main(void) {
	for (int i = 0; i < 3; i++) {
		for (int j = i+1; j < 4; j++)
		{
			for (int k = j+1; k < 5; k++)
			{
				printf("%d %d %d\n", i, j, k);
			}
		}
	}
	return 0;
}
#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>
int N = 0;
int A;
void test(int L, int start, int end) {
	if (L > N) {
		return;
	}
	for (int i = start; i < end; i++)
	{
		test(L + 1, i + 1, end + 1);
	}
}
int main(void) {
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++)
		{
			for (int k = j + 1; k < 5; k++)
			{
				printf("%d %d %d\n", i, j, k);
			}
		}
	}
	return 0;
}
#endif

// 백준 바이러스
// https://www.acmicpc.net/problem/2606
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // memset
#include <stdlib.h>
#define ARR_SIZE (101)
int V;
int E;
int adjM[ARR_SIZE][ARR_SIZE];  // 인접행렬
int adjL[ARR_SIZE][ARR_SIZE];  // 인접리스트
int answer;

void print_ary(int(*ary)[ARR_SIZE]) {
	int p;
	for (int i = 1; i <= V; ++i) {
		p = (ary[i][0] > 0) ? ary[i][0] : V;
		for (int j = 1; j <= p; ++j) {
			printf("%d ", ary[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
#if 0
void inputDataM() {
	int from, to;
	(void)scanf("%d %d", &V, &E);
	for (int i = 0; i < E; ++i) {
		(void)scanf("%d %d", &from, &to);
		adjM[from][to] = 1;
		adjM[to][from] = 1;
	}
}
#else
void inputDataL() {
	int from, to;
	(void)scanf("%d %d", &V, &E);
	for (int i = 0; i < E; ++i) {
		(void)scanf("%d %d", &from, &to);
		adjL[from][++adjL[from][0]] = to;
		adjL[to][++adjL[to][0]] = from;
	}
}
#endif
// 인접행렬 사용

int visit[ARR_SIZE] = { 0 };
void test_adjL(int curr) {
		for (int j = 1; j <= adjL[curr][0]; ++j) {
			if (adjL[curr][j] && visit[j] == 0) {
				visit[j] = 1;
				test_adjL(j);
				answer++;
			}
		}
}

void test_adjM(int curr) {
	visit[curr] = 1;
	for (int next = 1; next <= V; ++next) {
		if (adjM[curr][next] && visit[next] == 0) {
			
			test_adjM(next);
			answer++;
		}
	}
	
}
int main(void) {
	(void)freopen("B2606.txt", "r", stdin);
	inputDataL();
	print_ary(adjL);
	answer = 0;
	visit[1] = 1;
	test_adjL(1);
	printf("%d\n", answer);
	//inputDataL();
	return 0;
}
#endif