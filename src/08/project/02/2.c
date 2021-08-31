/**
 * Created by Linus Zhang on 2021/8/1.
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    int num_count[10] = {0};
    int digit;
    long num;

    printf("Enter a number: ");
    scanf("%ld", &num);

    while (num > 0) {
        digit = (int) (num % 10);
        num_count[digit]++;
        num /= 10;
    }

    printf("Digit:\t\t");
    for (digit = 0; digit < 10; digit++) {
        printf(" %d", digit);
    }
    printf("\nOccurrences:");
    for (digit = 0; digit < 10; digit++) {
        printf(" %d", num_count[digit]);
    }
    printf("\n");
    return 0;
}