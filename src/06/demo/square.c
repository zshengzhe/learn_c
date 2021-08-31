/**
 * Created by Linus Zhang on 2021/7/29.
 */
#include <stdio.h>

int main(void)
{
    int num, i;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &num);

    for (i = 1; i <= num; i++) {
        printf("%10d%10d", i, i * i);
    }
    return 0;
}
