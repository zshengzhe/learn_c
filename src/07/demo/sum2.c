/**
 * Created by Linus Zhang on 2021/7/30.
 */

#include <stdio.h>

int main(void)
{
    long n, sum = 0;

    printf("This program sums a series of integers.\n");
    printf("Enter integers (0 to terminate): ");

    scanf("%ld", &n);
    while (n != 0) {
        scanf("%ld", &n);
    }

    printf("The sum is: %ld\n", sum);
    return 0;
}