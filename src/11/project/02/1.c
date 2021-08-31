/**
 * Created by Linus Zhang on 2021/8/4.
 */

#include <stdio.h>
#include <ctype.h>

#define N 100

int main(void)
{
    int h, t, size = 0;
    char ch, arr[N];
    printf("Enter a message: ");
    while ((ch = toupper(getchar())) != '\n' && size < N) {
        if (isalpha(ch))
            arr[size++] = ch;
    }
    h = 0;
    t = size - 1;
    while (h != t) {
        if (arr[h++] != arr[t--]) {
            printf("Not a palindrome");
            return 0;
        }
    }
    printf("Palindrome");

    return 0;
}