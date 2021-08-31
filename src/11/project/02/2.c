/**
 * Created by Linus Zhang on 2021/8/4.
 */

#include <stdio.h>
#include <ctype.h>

#define N 100

int main(void)
{
    char *h, *p, ch, arr[N];
    p = arr;
    printf("Enter a message: ");
    while ((ch = toupper(getchar())) != '\n' && p < arr + N) {
        if (isalpha(ch))
            *p = ch;
    }
    h = arr;
    while (h != p) {
        if (*h++ != *p--) {
            printf("Not a palindrome");
            return 0;
        }
    }
    printf("Palindrome");

    return 0;
}