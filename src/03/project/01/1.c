/**
 * Created by Linus Zhang on 2021/7/28.
 */

#include <stdio.h>

int main(void)
{
    int month, day, year;
    printf("Enter a date (mm/dd/yy): ");
    scanf("%d/%d/%d", &month, &day, &year);

    printf("You entered the date %.4d/%.2d/%.2d\n", year, month, day);

}