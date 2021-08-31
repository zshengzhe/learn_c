/**
 * Created by Linus Zhang on 2021/8/1.
 */

#include <stdio.h>

int main(void)
{
    int sum = 0;
    char ch;
    printf("Enter a sentence: ");

    while ((ch = getchar()) != '\n') {
        switch (ch) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                sum++;
                break;
            default:
                break;
        }
    }

    printf("Your sentence contains %d vowels\n", sum);

    return 0;
}