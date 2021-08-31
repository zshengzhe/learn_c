/**
 * Created by Linus Zhang on 2021/8/1.
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int sum = 0;

    printf("Enter a word: ");

    while ((ch = (char) getchar()) != '\n') {
        switch (toupper(ch)) {
            case 'A':
            case 'E':
            case 'I':
            case 'L':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
                sum++;
                break;
            case 'D':
            case 'G':
                sum += 2;
                break;
            case 'B':
            case 'C':
            case 'M':
            case 'P':
                sum += 3;
                break;
            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                sum += 4;
                break;
            case 'K':
                sum += 5;
                break;
            case 'J':
            case 'X':
                sum += 8;
                break;
            case 'Q':
            case 'Z':
                sum += 10;
                break;
            default:
                break;
        }
    }
    printf("Scrabble value: %d\n", sum);
    return 0;
}