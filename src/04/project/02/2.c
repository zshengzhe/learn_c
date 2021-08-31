/**
 * Created by Linus Zhang on 2021/7/28.
 */

#include <stdio.h>

int main(void)
{
    int num, ones_place, ten_place, hundred_place;
    printf("Enter a three-digit number: ");
    scanf("%3d", &num);

    hundred_place = num / 100;
    num -= 100 * hundred_place;
    ten_place = num / 10;
    ones_place = num % 10;

    printf("The reversal is: %1d%1d%1d\n", ones_place, ten_place, hundred_place);
    return 0;
}