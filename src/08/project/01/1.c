/**
 * Created by Linus Zhang on 2021/8/1.
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool digit_seen[10] = {false};
    bool repeated[10] = {false};
    int digit;
    long num;

    printf("Enter a number: ");
    scanf("%ld", &num);

    while (num > 0) {
        digit = (int) (num % 10);
        if (digit_seen[digit]) {
            repeated[digit] = true;
        }
        digit_seen[digit] = true;
        num /= 10;
    }

    printf("Repeated digit(s):");
    for (digit = 0; digit < 10; digit++) {
        if (repeated[digit]) {
            printf(" %d", digit);
        }
    }
    printf("\n");
    return 0;
}