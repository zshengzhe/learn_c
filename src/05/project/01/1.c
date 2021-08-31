/**
 * Created by Linus Zhang on 2021/7/29.
 */

#include <stdio.h>

int main(void)
{
    int num, digit = 0;

    printf("Enter a number: ");
    scanf("%4d", &num);

    if (num >= 0 && num <= 9)
        digit = 1;
    else if (num <= 99)
        digit = 2;
    else if (num <= 999)
        digit = 3;
    else if (num <= 9999)
        digit = 4;

    printf("The number %d has %d digits\n", num, digit);

    return 0;
}