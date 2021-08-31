/**
 * Created by Linus Zhang on 2021/8/4.
 */

#include <stdio.h>

#define N 100

int main(void)
{
    int i, n = 0;
    char ch;
    char arr[N];
    printf("Enter a message: ");

    while ((ch = getchar()) != '\n' && n <= N) {
        arr[n++] = ch;
    }

    printf("Reversal is: ");
    for (i = n - 1; i >= 0; i--)
        putchar(arr[i]);

    return 0;
}