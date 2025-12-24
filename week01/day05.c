#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void){
return 0;
}
int my_strcpy(char* src, char* dest) {
	char* save = src;
	for (; *src; src++);
	while(src)
}
#endif
#if 0
const int a;
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int* p = &a;
	*p = 20;
	printf("%d", a);
	
	return 0;
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void get_result(int (*score)[4],int r, int c) {
	int (*result)[2] = { 0 };
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				*(result+i)[0] += *(score+i)[j];
			}
			*(result+i)[1] /= c;
		}
		for (int i = 0; i < r; i++)
		{
				printf("score: %f,mean: %f\n",*(result+i)[0],*(result+i)[1]);
			
		}
}
int main(void) {
	int score[3][4] = { 0 };
	int i, j;
	(void)freopen("scores.txt", "r", stdin);
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 4; j++)
		{
			(void)scanf("%d", &score[i][j]);
		}
	}
	get_result(score, 3, 4);
	return 0;
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void get_result(int (*score)[4], int r, int c) {
	float result = 0;
	for (int i = 0; i < r; i++)
	{
		result = 0;
		for (int j = 0; j < c; j++)
		{
			result += score[i][j];
		}
		printf("score: %f,mean: %f", result, result / c);
	}
}
int main(void) {
	int score[3][4] = { 0 };
	int i, j;
	(void)freopen("scores.txt", "r", stdin);
	for (i = 0; i < 12; i++)
	{
			(void)scanf("%d", score[0] + i);
	}
	get_result(score, 3, 4);
	return 0;
}
#endif