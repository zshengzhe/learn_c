/**
 * Created by Linus Zhang on 2021/8/4.
 */

#include <stdio.h>

#define N 100

int main(void)
{
    char ch;
    char arr[N];

    char *p = arr;
    printf("Enter a message: ");
    while ((ch = getchar()) != '\n' && p < arr + N) {
        *p++ = ch;
    }

    printf("Reversal is: ");
    for (; p >= arr; p--)
        putchar(*p);

    return 0;
}