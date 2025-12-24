#define _CRT_SECURE_NO_WARNINGS

#include "file_io.h"
#include<stdio.h>
#include<stdlib.h>


// user-cnt + 1 개의 t_user 구조체를 저장할 수 있는 공간을 할당하여 반환
// 만일 메모리가 부족한 경우 NULL 반환
t_user* init_struct(int user_cnt){
	
	return (t_user*)calloc(user_cnt + 1, sizeof(t_user));
}
// fp에 연결된 파일에서 users에 user_cnt개 만큼의 데이터를 읽어오기
// 읽어온 데이터 개수를 반환, 만일 오류가 발생하면 0 반환
int input_data(FILE *fp, t_user* users, int user_cnt) {
	t_user temp = { 0 };
	int i = 0;
	for (i = 0; i < user_cnt; i++)
	{
		
		(void)fscanf(fp," %[^\n] %d",temp.name ,&temp.score);
		users[i] = temp;
	}
	return i;
}
// 화면에 users에 있는 데이터를 user_cnt개 만큼 출력
void print_data(t_user* users, int user_cnt) {
	for (size_t i = 0; i < user_cnt; i++)
	{
		printf("%s %d\n", users[i].name, users[i].score);
	}
}