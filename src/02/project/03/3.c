/**
 * Created by Linus Zhang on 2021/7/14.
 */

#include <stdio.h>

#define EXPRESSION(r) 4.0f / 3.0f / 3.14f * (r * r * r)

int main(void)
{
    float r;

    printf("Enter radius: ");
    scanf("%f", &r);

    printf("Sphere volume: %.2f cubic meters\n", EXPRESSION(r));

    return 0;
}