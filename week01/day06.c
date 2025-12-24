#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	int a[3][4] = { 1,2,3,4,5,6,7,8,9,0,1,2 };
	printf("sizeof &(a)[0] : %d\n", sizeof(&(a)[0]));

	printf("sizeof &(a)[0] : %d\n", sizeof(a[0][0]));

	printf("sizeof *a : %d\n", sizeof(*a));
	printf("sizeof a : %d\n", sizeof(a));
	return 0;
}

#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void exchange0(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
void exchange1(int** ap, int** bp);
void exchange2(int*** app, int*** bpp);
void exchange3(int** ap, int** bp);
void exchange4(int*** app, int*** bpp);
void exchange5(int*** app, int*** bpp);
int main(void) {
	int a = 10, b = 5;
	int* ap = &a, * bp = &b;
	int** app = &ap, ** bpp = &bp;
	printf("BEFORE : %d %d \n ", a, b);
	exchange0(&a, &b);
	printf("AFTER0 : %d %d \n ", a, b);
	printf("BEFORE : %d %d \n ", a, b);
	exchange1(&ap, &bp);
	printf("AFTER1 : %d %d \n ", a, b);
	printf("BEFORE : %d %d \n ", a, b);
	exchange2(&app, &bpp);
	printf("AFTER2 : %d %d \n ", a, b);
	printf("BEFORE : %p %p \n ", ap, bp);
	exchange3(&ap, &bp);
	printf("AFTER3 : %p %p \n ", ap, bp);
	printf("BEFORE : %p %p \n ", ap, bp);
	exchange4(&app, &bpp);
	printf("AFTER : %p %p \n ", ap, bp);
	printf("BEFORE : %p %p \n ", app, bpp);
	exchange5(&app, &bpp);
	printf("AFTER : %p %p \n ", app, bpp);
	return 0;
}
void exchange1(int** ap, int** bp) {
	int temp = **ap;
	**ap = **bp;
	**bp = temp;
}
void exchange2(int*** app, int*** bpp) {
	int temp = ***app;
	***app = ***bpp;
	***bpp = temp;
}
void exchange3(int** ap, int** bp) {
	int* temp = *ap;
	*ap = *bp;
	*bp = temp;
}
void exchange4(int*** app, int*** bpp) {
	int* temp = **app;
	**app = **bpp;
	**bpp = temp;
}
void exchange5(int*** app, int*** bpp) {
	int* temp = *app;
	*app = *bpp;
	*bpp = temp;
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sum(int x, int y);
int sub(int x, int y);
int mul(int x, int y);
int divi(int x, int y);
int mod(int x, int y);
int main(void) {
	int a=10;
	int b=5;
	int (*my_func)(int, int) = sum;
	int (*func[5])(int, int) = { sum,sub,mul,divi,mod };
	for (int i = 0; i < 5; i++)
	{
		printf("%d + %d = %d\n", a, b, func[i](a, b));
	}
	
	return 0;
}
int sum(int x, int y) {
	return x + y;
}
int sub(int x, int y) {
	return x - y;
}
int mul(int x, int y) {
	return x* y;
}
int divi(int x, int y) {
	return x / y;
}
int mod(int x, int y) {
	return x % y;
}

#endif