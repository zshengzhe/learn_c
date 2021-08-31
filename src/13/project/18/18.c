/**
 * Created by Linus Zhang on 2021/8/7.
 */

#include <stdio.h>

int main(void)
{
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    int m, d, y;
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &m, &d, &y);

    printf("You entered the date %s %d, %d", months[m - 1], d, y);

    return 0;
}