/**
 * Created by Linus Zhang on 2021/7/29.
 */

#include <stdio.h>

int main(void)
{
    int digits = 0, num;

    printf("Enter a nonnegative integers: ");
    scanf("%d", &num);

    do {
        num /= 10;
        digits++;
    } while (num > 0);

    printf("The number has %d digit(s).\n", digits);

    return 0;
}