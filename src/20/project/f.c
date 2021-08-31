/**
 * Created by Linus Zhang on 2021/8/22.
 */

#include <stdio.h>

struct float_value {
    unsigned int fraction: 23;
    unsigned int exponent: 8;
    unsigned int sign: 1;
};

union f {
    float data;
    struct float_value fv;
};

int main(void )
{
    struct float_value fv;
    fv.sign = 1;
    fv.exponent = 128;
    fv.fraction = 0;

    union f u;
    u.fv = fv;

    printf("%.2f", u.data);
}