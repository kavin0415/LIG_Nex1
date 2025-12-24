#if 00
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  
#include <stdlib.h>
#define ARR_SIZE (25 + 2)

int N;
int map[ARR_SIZE][ARR_SIZE];
int cnt;
int cnt_array[(ARR_SIZE * ARR_SIZE) / 2] = { 0 };
int visited[ARR_SIZE][ARR_SIZE];
int dr[4] = { -1, 1, 0, 0 }; // 위, 아래, 왼쪽, 오른쪽
int dc[4] = { 0, 0, -1, 1 };
void print_ary(int (*ary)[ARR_SIZE], int sr, int sc, int er, int ec);
void inputData(void);
void outputData(void);
int comp(const void* a,const void* b);
void danji(int r, int c);

int main(void) {
    int i, j;
    //(void)freopen("B2667.txt", "r", stdin);
    inputData();
    //print_ary(map, 1, 1, N, N);
    cnt = 0;
    for (i = 1; i <= N; ++i) {
        for (j = 1; j <= N; ++j) {
            if (map[i][j] == 1 && visited[i][j] == 0) {
                danji(i, j);
                cnt++;
            }
        }
    }
    //print_ary(map, 1, 1, N, N);
    qsort(cnt_array, cnt, sizeof(cnt_array[0]), comp);

    outputData();
    

    
    return 0;
}
void danji(int r, int c) {
    int nr, nc;
    map[r][c] = cnt + 1;
    visited[r][c] = 1;
    printf("danji : x%d %d \n", r, c);
    cnt_array[cnt]++;
    for (int i = 0; i < 4; ++i) {
        nr = r + dr[i];
        nc = c + dc[i];
        //if (map[nr][nc] != 1 || visited[nr][nc] == 1) continue;
        if (map[nr][nc] == 1 && visited[nr][nc] == 0) {
            danji(nr, nc);
        }
    }
}


int comp(const void* a,const void* b) {
    if ( *(int*)a > *(int*)b) {
        return 1; 
    }
    else {
        return -1;
    }
}
void outputData(void) {
    printf("%d\n", cnt);
    for (int i = 0; i < cnt; i++)
    {
        if (cnt_array[i] == 0) return;
        printf("%d\n", cnt_array[i]);
    }
}
void print_ary(int (*ary)[ARR_SIZE], int sr, int sc, int er, int ec) {
    int i, j;
    for (i = sr; i <= er; ++i) {
        for (j = sc; j <= ec; ++j) {
            printf("%d ", ary[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void inputData(void) {
    int i, j;
    char temp[27] = { 0 };
    (void)scanf("%d", &N);
    for (i = 1; i <= N; ++i) {
        (void)scanf("%s", temp + 1);
        for (j = 1; j <= N; ++j) {
            map[i][j] = temp[j] - '0';
        }
    }
}


#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>   
#include<stdlib.h>
int main(void) {
    int N, K;
    (void)scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
    {
        if (N%i ==0) {
            K--;
            if (K == 0) {
                printf("%d", i);
                break;
            }
        }
    }
    if (K > 0) {
        printf("0");
    }
    return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define ARR_SIZE (13+2)
int answer = INT_MAX;
int cost[ARR_SIZE][ARR_SIZE];
int visited[ARR_SIZE] = { 0 };
int N;

void input_data(void);
void print_ary(int (*ary)[ARR_SIZE], int sr, int sc, int er, int ec);
void hamilton(int cur, int sum, int depth);

int main(void) {
    //(void)freopen("hamilton.txt", "r", stdin);

    input_data();
    //print_ary(cost, 1, 1, N, N);
    hamilton(1, 0, 1);
    printf("%d", answer);
    return 0;
}
void hamilton(int cur, int sum, int depth)
{
    if (cost >= answer) return;
    if (depth >= N) {
        if (cost[cur][1] == 0)
            return;

        if (answer > sum + cost[cur][1])
            answer = sum + cost[cur][1];
        return;
    }
    for (int i = 2; i <= N; ++i)
    {
        if (visited[i] != 1 && cost[cur][i] != 0)
        {
            visited[i] = 1;
            hamilton(i, sum + cost[cur][i], depth + 1);
            visited[i] = 0;
        }
    }


    return;
}
void input_data(void) {
    int i, j;
    (void)scanf("%d", &N);
    for (i = 1; i <= N; ++i) {
        for (j = 1; j <= N; ++j) {
            (void)scanf("%d", &(cost[i][j]));
        }

    }
}
void print_ary(int (*ary)[ARR_SIZE], int sr, int sc, int er, int ec) {
    int i, j;
    for (i = sr; i <= er; ++i) {
        for (j = sc; j <= ec; ++j) {
            printf("%d ", ary[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#define ARR_SIZE (13+2)
int count = 0;
int c_visited[ARR_SIZE] = { 0 };
int rd_visited[ARR_SIZE * 2] = { 0 };
int ru_visited[ARR_SIZE * 2 +1] = { 0 };

int N;

void input_data(void);
void nqueen(int r);

int main(void) {
    //(void)freopen("nqueen.txt", "r", stdin);

    input_data();
    nqueen(1);
    printf("%d", count);
    return 0;
}
void nqueen(int r)
{
    if (r > N) {
        count++;
        return;
    }
    for (int c= 1; c<=N; c++)
    {
        if (c_visited[c] != 1 && rd_visited[r-c+N]!=1&& ru_visited[r + c] != 1) {
            c_visited[c] = 1;
            rd_visited[r - c + N] = 1;
            ru_visited[r + c] = 1;
            nqueen(r + 1);
            c_visited[c] = 0;
            rd_visited[r - c + N] = 0;
            ru_visited[r + c] = 0;
        }
    }
}
void input_data(void) {
    
    (void)scanf("%d", &N);
    
}
void print_ary(int (*ary)[ARR_SIZE], int sr, int sc, int er, int ec) {
    int i, j;
    for (i = sr; i <= er; ++i) {
        for (j = sc; j <= ec; ++j) {
            printf("%d ", ary[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
#endif