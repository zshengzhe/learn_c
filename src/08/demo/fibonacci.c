/**
 * Created by Linus Zhang on 2021/8/1.
 */

#include <stdio.h>

#define N 40

int main(void)
{
    int i;
    int arr[N] = {0};
    arr[0] = 0;
    arr[1] = 1;

    for (i = 2; i < N; i++) {
        arr[i] = arr[i - 2] + arr[i - 1];
    }

    printf("Fibonacci numbers:");
    for (i = 0; i < N; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    return 0;
}