#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // memset
#include <stdlib.h>
#define string(x)  printf(#x " is %d\n", x)
#define charr(x) printf("%c is %c\n", #@x, x)
#define concat(x, i) printf("%c%c is %d\n", #@x, #@i, x##i)
#define concat2(x, i) printf("%s%s is %d\n", #x, #i, x##i)

int main(void)
{
    int s = 10, c = 97, ca = 7, cb = 9;
    int ccbb = 20;
    string(s);  // s is 10   printf("s is %d\n", s);
    charr(c);   // c is a    printf("%c is %c\n", 'c', c);
    concat(c, a);  // ca is 7   printf("%c%c is %d\n", 'c', 'a', ca)
    concat2(cc, bb);  // ccbb is 20  printf("%s%s is %d\n", "cc", "bb", x##i)
    return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // memset
#include <stdlib.h>
// 구조체 멤버 접근
struct Point {
    int x, y;
};
#define GET_MEMBER(p, m) ((p).m)
void f_pre01(void) {
    struct Point pt = { 1, 2 };
    printf("%d\n", GET_MEMBER(pt, y));  // → pt.y → 2
}
//#define DEBUG_VAR(x) printf("[DEBUG] %s = %d (in %s:%d)\n", #x, x, __FILE__, __LINE__)
#define DEBUG_VAR(x) (printf("[DEBUG] "#x " : %d (in %s:%d)\n", x, __FILE__,__LINE__))

void f_pre02(void) {
    int score = 80;
    DEBUG_VAR(score);  // [DEBUG] score = 80 (in 파일이름:라인번호)
}

int main(void) {
    f_pre02();
    return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // memset
#include <stdlib.h>
//#define NDEBUG
#include <assert.h>

void f_func(void) {
    int x;
    printf("\nEnter an integer value: ");
    (void)scanf("%d", &x);
    assert(x >= 0);
    printf("You entered %d.", x);
}

int main(void) {
    f_func();
    return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>  // memset
#include <stdlib.h>
#include "file_io.h"
#define USER_NAME_MAX 30

int main(void) {
    int user_cnt = 0;
    t_user* users = NULL;
    FILE* fp = NULL;
    // userlist2.txt 파일 열기 (읽기전용)
    fp = fopen("userlist2.txt", "r");
    if (fp == NULL) {
        printf("파일을 열지 못했습니다");
        exit(1);
    }
    (void)fscanf(fp, "%d", &user_cnt);
    users = init_struct(user_cnt);
    input_data(fp,users,user_cnt);
    print_data(users,user_cnt);
    // 사용했던 리소스 해지
    free(users);
    fclose(fp);
    return 0;
}
#endif