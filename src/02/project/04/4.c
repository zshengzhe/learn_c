/**
 * Created by Linus Zhang on 2021/7/14.
 */

#include <stdio.h>

int main(void )
{
    float amount;

    printf("Enter an amount: ");
    scanf("%f", amount);

    printf("With tax added: $%.2f\n", amount * 1.05f);

    return 0;
}