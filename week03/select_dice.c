#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// dice_rows는 2차원 배열 dice의 행 길이, dice_cols는 2차원 배열 dice의 열 길이입니다.
int* solution(int** dice, size_t dice_rows, size_t dice_cols) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(5 * sizeof(int));




    return answer;
}
int main(void) {
    size_t dice_rows = 4;
    size_t dice_cols = 6;
    int** dice = (int*)malloc(sizeof(int) * dice_rows * dice_cols);
    int dice_test[4][6] = {
        {40, 41, 42, 43, 44, 45},
        {43, 43, 42, 42, 41, 41},
        {1, 1, 80, 80, 80, 80},
        {70, 70, 1, 1, 70, 70}
     };


    int* ans;
    ans = solution(dice, dice_rows, dice_cols); // 왜 dice_cols를 받는거지? 항상 6인데...
    printf(" %d", solution);
}