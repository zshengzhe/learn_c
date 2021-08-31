/**
 * Created by Linus Zhang on 2021/7/30.
 */

#include <stdio.h>

int factorial(int i);

int main(void)
{
    float e = 1.0f;
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++) {
        e += 1.0f / (float) factorial(i);
    }
    printf("e = %.10f\n", e);

    return 0;
}

int factorial(int i)
{
    int sum = 1;
    for (; i > 1; i--) {
        sum *= i;
    }
    return sum;
}
