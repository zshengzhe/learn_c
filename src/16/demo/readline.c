/**
 * Created by Linus Zhang on 2021/8/11.
 */

#include <ctype.h>
#include <stdio.h>
#include "readline.h"

int read_line(char str[], int n)
{
    int ch, i = 0;

    while (isspace(ch = getchar()))
        ;

    while (ch != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = (char) ch;
        ch = getchar();
    }

    str[i] = '\0';
    return i;
}