/**
 * Created by Linus Zhang on 2021/8/1.
 */

#include <stdio.h>

double average(double x, double y)
{
    return (x + y) / 2;
}

int main(void)
{
    double x, y, z;

    printf("Enter three number: ");
    scanf("%lf %lf %lf", &x, &y, &z);

    printf("Average of %g and %g: %g\n", x, y, average(x, y));
    printf("Average of %g and %g: %g\n", x, z, average(x, z));
    printf("Average of %g and %g: %g\n", y, z, average(y, z));

    return 0;
}