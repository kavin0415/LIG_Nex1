#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

unsigned int setBit(unsigned int num, int bitPosition) {
	return num | (1 << bitPosition);
}
unsigned int clearBit(unsigned int num, int bitPosition) {
	return num & ~(1 << bitPosition);
}
unsigned int toggleBit(unsigned int num, int bitPosition) {
	return num ^ (1 << bitPosition);
}

unsigned int setBits(unsigned int num, int start, int count) {
	return num | (((1 << count) - 1) << start);
}
unsigned int clearBits(unsigned int num, int start, int count) {
	return num & ~(((1 << count) - 1) << start);
}
unsigned int toggleBits(unsigned int num, int start, int count) {
	return num ^ (((1 << count) - 1) << start);
}
static unsigned int isBitSet(unsigned int num, int bitPosition) {
	return (num & (1 << bitPosition)) >> bitPosition;
}

int main() {
	unsigned int num = 0b10101010;
	num = isBitSet(num, 1);

	printf("After setting bit 2-2: %X\n", num);
	num = isBitSet(0b10101010, 2);

	printf("After setting bit 2-2: %X\n", num);
	char x = -128;
	char y = -129;
	for (int i = -128; i < 127; i++)
	{
		printf("%d : %c\n", i, i);
	}
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//difference between if else  and  ?:
	int a = 10;
	if (a >= 0) {
		a = 1;
	}
	else {
		a = -1;
	}


	a = (a >= 10) ? 1 : -1;
	return 0;
	//in assenbly.. same code
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	char* grade = "FFFFFFDCBAA";
	int n;
	scanf("%d", &n);
	printf("%c", grade[n/10]);
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int a;
	while (scanf("%d", &a) && a > 10);
	printf("%d", a);
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int a=0;
	int sum = 0;
	while (scanf("%d",&a) && a!=0) if (a>0) sum += a;
	printf("%d", sum);
	return 0;
}
#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int try = 0;
	int pw = 1357;
	while (try < 3 && scanf("%d", &pw) && pw != 1357) ++try;
	if (pw == 1357) printf("로그인 성공!");
	else printf("관리자에게 문의하세요");
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int n = 0;
	int c = 0;
	scanf("%d", &n);
	while (n /= 10 && ++c);
	printf("%d", c+1);
	return 0;
}
#endif