/**
 * Created by Linus Zhang on 2021/8/7.
 */

#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = argc - 1; i > 0; i--)
        printf("%s ", argv[i]);
    printf("\n");
    return 0;
}