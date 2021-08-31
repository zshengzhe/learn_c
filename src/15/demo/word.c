/**
 * Created by Linus Zhang on 2021/8/10.
 */

#include <stdio.h>
#include "word.h"

int read_char(void)
{
    int ch = getchar();

    if (ch == '\n' || ch == '\t')
        return ' ';

    return ch;
}

void read_word(char *word, int len)
{
    int ch, pos = 0;

    while ((ch = getchar()) == ' ');

    while ((ch = getchar()) != ' ' && ch != EOF) {
        if (pos < len)
            word[pos++] = ch;
        ch = read_char();
    }
    word[pos] = '\0';
}