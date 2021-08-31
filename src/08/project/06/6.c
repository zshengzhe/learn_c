/**
 * Created by Linus Zhang on 2021/8/1.
 */

#include <stdio.h>

#define TO_CAPITAL(ch) (ch - 'a' + 'A')

void print_capital_or_origin(char ch);

int main(void)
{
    printf("Enter message: ");
    char ch;

    while ((ch = getchar()) != '\n') {
        switch (ch) {
            case 'A':
            case 'a' :
                putchar('4');
                break;
            case 'B':
            case 'b':
                putchar('8');
                break;
            case 'E':
            case 'e':
                putchar('3');
                break;
            case 'I':
            case 'i':
                putchar('1');
                break;
            case 'O':
            case 'o':
                putchar('0');
                break;
            case 'S':
            case 's':
                putchar('5');
                break;
            default:
                print_capital_or_origin(ch);
                break;
        }

    }
    printf("!!!!!!!!!!");
    return 0;
}

void print_capital_or_origin(char ch)
{
    if (ch >= 'a' && ch <= 'z') {
        putchar(TO_CAPITAL(ch));
        return;
    }
    putchar(ch);
}