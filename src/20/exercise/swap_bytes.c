/**
 * Created by Linus Zhang on 2021/8/22.
 */

#include <stdio.h>

unsigned short swap_bytes(unsigned short i)
{
    return (i << 8) | (i >> 8);
}

int main(void)
{
    unsigned short i;
    printf("Enter a hexadecimal number (up to four digits): ");
    scanf("%hx", &i);

    printf("Number with bytes swapped: %hx", swap_bytes(i));
}