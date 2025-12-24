// 구조체로 노드 구성
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ARR_SIZE (100)

typedef struct _node {
	int r;
	int c;
	int cost;
}node_t;

node_t Queue[ARR_SIZE];
int front, rear;  // 1씩 증가하는 읽기, 쓰기 위치

// 데이터를 맨 뒤에 삽입
void enqueue1(int r, int c, int cost) {
	// queue가 가득 찬 상태인지 확인 (FULL)
	// queue의 rear위치에 삽입하고, rear를 1 증가
	if (rear >= ARR_SIZE) {
		printf("FULL!");
		return;
	}
	Queue[rear].r = r;
	Queue[rear].c = c;
	Queue[rear++].cost = cost;
}

// 데이터를 맨 뒤에 삽입
void enqueue2(node_t data) {
	// queue가 가득 찬 상태인지 확인 (FULL)
	// queue의 rear위치에 삽입하고, rear를 1 증가
	if (rear >= ARR_SIZE) {
		printf("FULL!");
		return;
	}
	Queue[rear++] = data;
}

// 데이터를 맨 뒤에 삽입
void enqueue3(node_t* data) {
	// queue가 가득 찬 상태인지 확인 (FULL)
	// queue의 rear위치에 삽입하고, rear를 1 증가
	if (rear >= ARR_SIZE) {
		printf("FULL!");
		return;
	}
	Queue[rear++] = *data;
}

node_t dequeue1(void) {
	// queue에 데이터가 존재하는지 확인 (EMPTY)
	// queue의 front위치의 데이터를 반환하고, front를 1 증가
	if (front == rear) {
		printf("EMPTY!");
		return (node_t) { 0, 0, 0 };
	}
	return Queue[front++];
}

node_t* dequeue2(void) {
	// queue에 데이터가 존재하는지 확인 (EMPTY)
	// queue의 front위치의 데이터를 반환하고, front를 1 증가
	if (front == rear) {
		printf("EMPTY!");
		return NULL;
	}
	return &Queue[front++];
}

int main(void) {
	node_t data = { 2, 2, 200 };
	front = rear = 0;
	enqueue1(1, 1, 100);
	enqueue2(data);
	enqueue2((node_t) { 3, 3, 300 });
	enqueue3(&data);
	data = dequeue1();
	printf("%d %d %d\n", data);
	printf("%d %d %d\n", data.r, data.c, data.cost);
	return 0;
}
#endif

// 1661 jungol
/*
BFS logic
1.시작점을 queue 에 넣는다.
2.queue 에 내용이 있는 동안 반복한다.
	2-1.queue 에서 정점을 꺼낸다.
	2-1.인접한 정점을 queue 에 넣는다.

*/
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  
#include <stdlib.h>
#define ARR_SIZE (100 + 2)
int X, Y;
int sX, sY, eX, eY;
int miro[ARR_SIZE][ARR_SIZE];
int dX[4] = { 0,0,-1,1 };
int dY[4] = { -1,1,0,0 };
typedef struct _node {
	int currX;
	int currY;
}node_t;
node_t Queue[ARR_SIZE * ARR_SIZE];
int front, rear;

void printData(int (*ary)[ARR_SIZE]);
void inputData(void);
int miroBFSint(int sX, int sY, int eX, int eY);

int main(void) {
	//(void)freopen("jungol.txt", "r", stdin);
	inputData();
	//printData(miro);
	printf("%d \n", miroBFSint(sX, sY, eX, eY));
	//printData(miro);
	return 0;
}

void printData(int (*ary)[ARR_SIZE]) {
	for (int i = 1; i <= Y; ++i) {
		for (int j = 1; j <= X; ++j) {
			printf("%d ", ary[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void inputData(void) {
	char temp[ARR_SIZE] = { 0 };
	(void)scanf("%d %d", &X, &Y);
	(void)scanf("%d %d %d %d", &sX, &sY, &eX, &eY);
	for (int i = 1; i <= Y; ++i) {
		(void)scanf("%s", temp + 1);
		for (int j = 1; j <= X; ++j) {
			miro[i][j] = (temp[j] - '0') ^ 1;
		}
	}
}
int miroBFSint(int sX, int sY, int eX, int eY) {
	node_t temp = { 0,0 };
	int nextX, nextY;
	front = rear = 0;
	Queue[rear++] = (node_t){ sX,sY };
	miro[sY][sX] = 2;
	while (front != rear)
	{
		temp = Queue[front++];

		for (int i = 0; i < 4; i++)
		{
			nextX = temp.currX + dX[i];
			nextY = temp.currY + dY[i];
			if (miro[nextY][nextX] == 1)
			{
				if (nextX == eX && nextY == eY)
					return miro[temp.currY][temp.currX] - 1;
				Queue[rear++] = (node_t){ nextX,nextY };
				miro[nextY][nextX] = miro[temp.currY][temp.currX] + 1;
			}
		}

	}
	return -1;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  
#include <stdlib.h>
#define ARR_SIZE (100+ 2)
int map[ARR_SIZE][ARR_SIZE];
int X;
int Y;
int sX;
int sY;
int front;
int rear;
int left_jug = 0;
int dX[4] = { 0,0,-1,1 };
int dY[4] = { -1,1,0,0 };

typedef struct _node {
	int currX;
	int currY;
}node_t;

node_t Queue[ARR_SIZE * ARR_SIZE];
void inputData();
int treasureBFSint(int currX, int currY);
void printData(int (*ary)[ARR_SIZE]);
int main(void) {
	//(void)freopen("jugling.txt", "r", stdin);
	inputData();
	//printData(map);
	treasureBFSint(sX, sY);
	//printData(map);

}
int treasureBFSint(int sX, int sY) {
	int nextX, nextY;
	node_t temp = { 0 };
	map[sY][sX] = 3;
	rear = front = 0;
	Queue[rear++] = (node_t){ sX, sY };
	while (front != rear) {
		temp = Queue[front++];
		for (int i = 0; i < 4; i++)
		{
			nextX = temp.currX + dX[i];
			nextY = temp.currY + dY[i];
			if (map[nextY][nextX] == 1) {
				Queue[rear++] = (node_t){ nextX,nextY };
				map[nextY][nextX] = map[temp.currY][temp.currX] + 1;
			}
		}
	}
	printf("%d \n", map[temp.currY][temp.currX]);
	for (int i = 1; i <= Y; i++)
	{
		for (int j = 1; j <= X; j++)
		{
			if (map[i][j] == 1)
				left_jug++;
		}
	}


	printf("%d\n", left_jug);

	return -1;
}
void inputData() {
	(void)scanf("%d %d", &X, &Y);
	char temp[ARR_SIZE];
	for (int i = 1; i <= Y; i++)
	{
		(void)scanf("%s", &(temp[1]));
		for (int j = 1; j <= X; j++)
		{

			map[i][j] = temp[j] - '0';
		}
	}
	(void)scanf("%d %d", &sX, &sY);

	return;
}
void printData(int (*ary)[ARR_SIZE]) {
	for (int i = 1; i <= Y; i++)
	{
		for (int j = 1; j <= X; j++)
		{

			printf("%d", map[i][j]);
		}
		printf("\n");

	}
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// int형 5개 공간을 힙에서 빌림 (초기화 X)
	int* pArr = (int*)malloc(sizeof(int) * 100);

	printf("=== 힙(Heap) 영역 쓰레기값 ===\n");
	for (int i = 0; i < 100; i++) {
		// 무엇이 나올지 모름 (이전 프로그램이 쓰던 찌꺼기)
		printf("pArr[%d] : %0x \n", i, pArr[i]);
	}

	free(pArr);
	return 0;
}
#endif


#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  
#include <stdlib.h>
#define ARR_MAX (100 + 2)
int X, Y;
int topX, topY;
int map[ARR_MAX][ARR_MAX] = { 0 };
int min_map[ARR_MAX][ARR_MAX];
int N;
int rear, front;
int dY[4] = { -1,1,0,0 };
int dX[4] = { 0,0,-1,1 };

typedef struct _node {
	int currX;
	int currY;
}node_t;

node_t Queue[ARR_MAX * ARR_MAX];
void inputData();
void printData(int (*ary)[ARR_MAX]);
int mountain();
int square(int a);
void reset_min_map() {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			min_map[i][j] = 0x7fffffff;
		}
	}
}
int main(void) {
	//(void)freopen("mountain.txt", "r", stdin);
	inputData();
	//printData(map);

	printf("%d \n", mountain());
	//printData(min_map);
	return 0;
}

int mountain() {
	reset_min_map();
	rear = front = 0;
	for (int i = 1; i <= N; ++i)
	{
		min_map[1][i] = square(map[1][i]);
		Queue[rear++] = (node_t){ i,1 };
		min_map[N][i] = square(map[N][i]);
		Queue[rear++] = (node_t){ i,N };
	}
	for (int i = 2; i < N; ++i)
	{
		min_map[i][1] = square(map[i][1]);
		Queue[rear++] = (node_t){ 1,i };
		min_map[i][N] = square(map[i][N]);
		Queue[rear++] = (node_t){ N,i };
	}

	while (rear != front)
	{
		int nextX, nextY;
		node_t temp = Queue[front++];
		for (int i = 0; i < 4; i++)
		{
			nextX = temp.currX + dX[i];
			nextY = temp.currY + dY[i];
			int nextH, nowH;
			int force = 0;
			nextH = map[nextY][nextX];
			nowH = map[temp.currY][temp.currX];
			force = (nextH > nowH) ? square(nextH - nowH) : nowH - nextH;
			if (min_map[nextY][nextX] > min_map[temp.currY][temp.currX] + force)
			{
				Queue[rear++] = (node_t){ nextX,nextY};
				min_map[nextY][nextX] = min_map[temp.currY][temp.currX] + force;
			}
		}

	}
	return min_map[topY][topX];
}
int square(int a) {
	return a * a;
}
void inputData() {
	(void)scanf("%d ", &N);
	(void)scanf("%d %d ", &topY, &topX);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			(void)scanf("%d ", &(map[i][j]));
		}


	}
	return;
}
void printData(int (*ary)[ARR_MAX]) {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{

			printf("%d ", ary[i][j]);
		}
		printf("\n");

	}
	return;
}
#endif

#if 01

#endif