/**
 * Created by Linus Zhang on 2021/8/21.
 */

#include <stdio.h>

unsigned int rotate_left(unsigned int i, int n)
{
    return (i << n) | (i >> (8 * sizeof(int) - n));
}

unsigned int rotate_right(unsigned int i, int n)
{
    return (i << (8 * sizeof(int) - n)) | (i >> n);
}

int count_ones(unsigned char ch)
{
    if (ch == 0)
        return 0;
    return count_ones(ch >> 1) + (ch & 0x1 ? 1 : 0);
}

unsigned int reverse_bits(unsigned int n)
{
    unsigned int r = 0;
    int i;
    for (i = 0; i < sizeof(unsigned int); i++) {
        r |= n & 0x1;
        r <<= 1;
        n >>= 1;
    }
    return r;
}

int main(void)
{
    unsigned int i = 0x8;
    printf("%x", reverse_bits(i));
}