/**
 * Created by Linus Zhang on 2021/8/23.
 */

#include <stdio.h>
#include <stddef.h>

struct s {
    char a;
    int b[2];
    float c;
} s1;

int main(void)
{
    printf("Size of struct s: %ld\n", sizeof(struct s));

    printf("Size and offset of member a: %ld -- %ld\n",
           sizeof(s1.a), offsetof(struct s, a));

    printf("Size and offset of member b: %ld -- %ld\n",
           sizeof(s1.b), offsetof(struct s, b));

    printf("Size and offset of member c: %ld -- %ld\n",
           sizeof(s1.c), offsetof(struct s, c));

    return 0;
}