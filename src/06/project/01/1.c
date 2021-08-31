/**
 * Created by Linus Zhang on 2021/7/29.
 */
#include <stdio.h>

int main(void)
{
    float max = 0.0f, num;

    do {
        printf("Enter a number: ");
        scanf("%f", &num);
        if (num > max)
            max = num;
    } while (num > 0);

    printf("The largest number entered was %.2f", max);

    return 0;
}
