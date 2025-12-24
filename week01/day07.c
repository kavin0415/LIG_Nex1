#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>	
#include<stdlib.h>
#include "basic_op.h"
int main(void) {
	int* pi;
	int size = 10;
	pi = (int*)malloc(size * sizeof(int));
	if (pi != NULL) {
		scanf_ary(pi, size);
		print_ary(pi, size);
		free(pi);

		printf("%p\n", pi);
		printf("%x ", pi[2]);
	}

	return 0;
}

#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>	
#include<stdlib.h>
#include "basic_op.h"
int main(void) {
	int* pi;
	int i, sum;
	int N = 5;

	pi = (int*)malloc(N * sizeof(int));
	if (pi != NULL) {
		printf("endter %d people's each age: ", N);
		for (i = 0; i < N; i++)
		{
			scanf("%d", pi + i);
		}
		double sum = avg_ary(pi, N);

		printf("\naverage age : %.1lf", sum);

	}
	free(pi);
	return 0;
}

#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>	//memset(addr, 0, length)
#include<stdlib.h>
#include "basic_op.h"
int main(void) {
	int* pi;
	int* tempP;
	int i, num;
	int N = 3;
	int step = 3;

	pi = (int*)calloc(N, sizeof(int));
	if (pi == NULL) {
		printf("run out of memory!");
		exit(1);
	}
	for (i = 0; scanf("%d", &num) && num != 0; i++)
	{
		if (i == N) {
			N += 3;
			tempP = (int*)realloc(pi, N * sizeof(int));

			if (tempP == NULL) {
				printf("run out of memory!");
				free(pi);
				exit(1);
			}
			pi = tempP;
			memset(pi + i, 0, step * sizeof(int));
		}
		pi[i] = num;
	}
	print_ary(pi, N);
	free(pi);
	return 0;
}

#endif



#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>	//memset(addr, 0, length)
#include<stdlib.h>
#include "basic_op.h"
void get_strings(char** str, int N);


int main(void) {
	char** str = 0;
	int N, i;
	(void)freopen("data.txt", "r", stdin);
	(void)scanf("%d", &N);
	(void)getchar();
	str = (char**)calloc(N, sizeof(char*));
	if (str == NULL) {
		printf("run out of memory!");
		exit(0);
	}

	get_strings(str, N);


	for (int j = 0; j < N; j++)
	{
		free(str[j]);
	}
	free(str);
	str = NULL;
	return 0;
}
void get_strings(char** str, int N) {
	char* temp[80];
	for (int i = 0; i < N; i++)
	{
		gets(temp);
		str[i] = (char*)calloc(strlen(temp) + 1, sizeof(char));
		if (str[i] == NULL) {
			printf("run out of memory!");
			for (int j = 0; j < i; j++)
			{
				free(str[j]);
			}
			free(str);
			exit(0);
		}
		strcpy(str[i], temp);

	}
}
void print_strings(char** str, int N) {
	for (int i = 0; i < N; i++)
	{
		printf("%s\n", str[i]);
	}
}
#endif



#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>	//memset(addr, 0, length)
#include<stdlib.h>
#include "basic_op.h"
void get_strings(char** str, int N);


int main(void) {
	char** str;
	int N;
	(void)freopen("data.txt", "r", stdin);
	(void)scanf("%d", &N);
	(void)getchar();
	str = (char**)calloc(N, sizeof(char*));

	get_strings(str, N);
	print_strings(str, N);
	destroy(N, str);


	str = NULL;
	return 0;
}
void get_strings(char** str, int N) {
	char* temp = (char*)calloc(N * 80, sizeof(char));
	if (str == NULL) {
		printf("run out of memory");
		free(str);
		exit(1);
	}
	for (int i = 0; i < N; i++)
	{
		gets(temp);
		str[i] = (char*)calloc(strlen(temp) + 1, sizeof(char));
		if (str[i] == NULL) {
			printf("run out of memory!");
			for (int j = 0; j < i; j++)
			{
				free(str[j]);
			}
			free(str);
			exit(0);
		}
		strcpy(str[i], temp);

	}
}
void print_strings(char** str, int N) {
	for (int i = 0; i < N; i++)
	{
		printf("%s\n", str[i]);
	}
}
void destroy(int N, char** str) {
	for (int j = 0; j < N; j++)
	{
		free(str[j]);
	}
	free(str);
}
#endif



// 고정길이 문자열  (char (*str)[80])
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // memset
#include <stdlib.h>
#include "basic_op.h"
typedef  char (*C80A)[80];
void* my_calloc(int N, int size);
void get_strings(int N, C80A str);
void print_string(int N, C80A str);

int main(void) {
	C80A str = NULL;
	int N;
	(void)freopen("data.txt", "r", stdin);
	(void)scanf("%d", &N);
	(void)getchar();
	str = (char (*)[80]) my_calloc(N, 80);
	get_strings(N, str);
	print_string(N, str);
	free(str);
	str = NULL;
	return 0;
}

void* my_calloc(int N, int size) {
	void* str = calloc(N, size);
	if (str == NULL) {
		printf("메모리가 부족합니다.\n");
		exit(0);
	}
	return str;
}

void get_strings(int N, C80A str) {
	int i;
	char temp[80] = { 0 };
	for (i = 0; i < N; ++i) {
		fgets(temp, 80, stdin);
		temp[strlen(temp) - 1] = '\0';
		strcpy(str[i], temp);
	}
}

void print_string(int N, C80A str) {
	int i;
	for (i = 0; i < N; ++i) {
		printf("%s\n", str[i]);
	}
}

#endif



#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
struct student {
	int num;
	double grade;
	char name[35];

};

void print_student1(struct student temp);

int main(void) {
	struct student stu = { 1,3.7,"seongmo" };
	stu.num = 2;
	stu.grade = 4.5;
	strcpy(stu.name, "kevin");
	printf("%d %.1f %s\n", stu.num, stu.grade, stu.name);
	printf("%d", sizeof(stu));
	//print_student1(stu);
	print_student2(&stu);
	return 0;
}
void print_student1(struct student temp) { //복사
	printf("%d\n", sizeof(temp));
	printf("%dd %.1f %s\n", temp.num, temp.grade, temp.name);
}
void print_student2(struct student* p) { //복사
	printf("%d\n", sizeof(p));
	p->num = 3;
	(*p).grade = 4.1;
	strcpy(p->name, "Tom");
	printf("%dd %.1f %s\n", p->num, p->grade, p->name);
}
#endif



#if 0 //구조체 2
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
struct profile {
	int age;
	double height;
	char* name;
};
struct student {
	struct profile pf;
	int num;
	double grade;
};
struct student2 {
	struct profile* ppf;
	int num;
	double grade;
};
void print_student1(struct student temp);
void print_student(struct student2* std);
void print_student2(struct student2** stu);

int main(void) {
	struct profile p = { 0 };
	struct student2 B = { 0 };
	struct student2* C = &B;
	B.ppf = &p;
	B.ppf->age = 25;
	B.ppf->height = 175.5;
	B.ppf->name = "maclaurin";
	B.num = 3;
	B.grade = 3.14;

#if 0
	struct student A = { 0 };
	A.pf.age = 20;
	A.pf.height = 170.2;
	A.pf.name = "soyoung";
	A.num = 1;
	A.grade = 8.2;
	printf("%d %.1f %s %d %.1f\n", A.pf.age, A.pf.height, A.pf.name, A.num, A.grade);
	struct profile* p = &A.pf;
	printf("%d %.1f %s\n", p->age, p->height, p->name);
#endif
	print_student(&B);
	print_student2(&C);
	return 0;
}
void print_student2(struct student2** stu) {
	printf("age = %d", (*stu)->ppf->age);
}
void print_student(struct student2* std) {
	printf("%d %.1f %s %d %.1f\n", std->ppf->age,std->ppf->height,std->ppf->name,std->num, std->grade);
}
#endif


#if 0 //구조체 동적할당
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
struct student {
	int id;
	int* score;
	char* name;
};
int main(void) {
	struct student *stu = NULL;
	int N = 5;
	int M = 3;
	int S = 20;
	int *s_temp;
	int* n_temp;
	(void)freopen("student2.txt", "r", stdin);
	(void)scanf("%d %d", &N, &M);
	(void)getchar();

	stu = (struct student*)malloc(N * sizeof(struct student));
	if (stu == NULL) {
		printf("run out of memory");
		exit(1);
	}
	s_temp = (int*)calloc(N, sizeof(int));
	if (s_temp == NULL) {
		free(stu);
		printf("run out of memory");
		exit(1);
	}
	n_temp = (char*)calloc(N * S, sizeof(char));
	if (n_temp == NULL) {
		free(stu);
		free(s_temp);
		printf("run out of memory");
		exit(1);
	}
	
	//stu 각 요소의 멤버를 초기화
	//입력
	for (int i = 0; i < N; i++)
	{
		(void)scanf("%d %d %d %d %s", &(stu[i]->id), s_temp, s_temp + 1, s_temp + 2, stu->name);
		stu[i]->score = s_temp;
	}
	//출력
	for (int i = 0; i < N; i++)
	{
		(void)printf("%d %d %d %d %s", &(stu->id), stu->score[0], stu->score[1], stu->score[2], stu->name);
	}
	
	free(stu);
	free(s_temp); // free(stu[0].scores);  free(stu)보다 먼저 써야함
	free(n_temp);
	return 0;
}
#endif
#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h>
union {
	int temp;
	struct ST {
		unsigned char a : 1;
		unsigned char b : 5;
		unsigned char reverved : 2;
	} ST_T;
} option;

void main(void) {
	printf("%d\n", sizeof(option));
}
#endif