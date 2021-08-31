/**
 * Created by Linus Zhang on 2021/7/28.
 */

#include <stdio.h>

int main(void)
{
    int num, ones_place, ten_place;
    printf("Enter a two-digit number: ");
    scanf("%2d", &num);

    ten_place = num / 10;
    ones_place = num % 10;

    printf("The reversal is: %2d\n", ones_place * 10 + ten_place);
    return 0;
}