/**
 * Created by Linus Zhang on 2021/7/30.
 */

#include <stdio.h>
#include <stdlib.h>

void print_memory(void *p, int size)
{
    char *chp = (char *) p;

    printf("Print Memory Begin");
    printf("\n-----------\n");

    // 十六进制
    printf("Hexadecimal: 0x");
    for (int i = 0; i < size; i++)
        printf("%.2x ", *(chp + i));
    printf("\n-----------\n");

    // 十进制
    printf("Decimal: ");
    for (int i = 0; i < size; i++)
        printf("%d ", *(chp + i));
    printf("\n-----------\n");

    printf("Print Memory End");
}

int main(void)
{
    int *i = malloc(sizeof(int));
    *i = 'a';
    print_memory(i, sizeof(int));
}