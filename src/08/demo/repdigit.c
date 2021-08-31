/**
 * Created by Linus Zhang on 2021/8/1.
 */

#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool digit_seen[10];
    int digit;
    long num;

    printf("Enter a number: ");
    scanf("%ld", &num);

    while (num > 0) {
        digit = (int) (num % 10);
        if (digit_seen[digit]) {
            break;
        }
        digit_seen[digit] = true;
        num /= 10;
    }

    if (num > 0)
        printf("Repeated digit\n");
    else
        printf("No repeated digit\n");

    return 0;
}