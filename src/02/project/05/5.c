/**
 * Created by Linus Zhang on 2021/7/14.
 */

#include <stdio.h>

#define EXPRESSION(x) (3 * x * x * x * x *x) + (2 * x * x * x * x) - (5 * x * x * x) - (x * x) + (7 * x) - 6

int main(void)
{

    int x = 0;

    printf("Enter value for x: ");
    scanf("%d", &x);

    printf("Result: %d\n", EXPRESSION(x));

    return 0;
}