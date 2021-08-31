/**
 * Created by Linus Zhang on 2021/8/3.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0;

void make_empty(void);

void push(char ch);

char pop(void);

bool is_empty(void);

bool is_full(void);

int main(void)
{
    char ch, tmp;
    printf("Enter parents and/or braces: ");
    while ((ch = getchar()) != '\n') {
        switch (ch) {
            case '(':
            case '[':
            case '{':
                push(ch);
                break;
            case ')':
                tmp = pop();
                if (tmp != '(') {
                    printf("NO");
                    return 0;
                }
                break;
            case ']':
                tmp = pop();
                if (tmp != '[') {
                    printf("NO");
                    return 0;
                }
                break;
            case '}':
                tmp = pop();
                if (tmp != '{') {
                    printf("NO");
                    return 0;
                }
                break;
            default:
                printf("must input ( ) [ ] { }.\n");
                exit(EXIT_FAILURE);
        }
    }
    if (is_empty()) {
        printf("YES");
    } else {
        printf("NO");
    }

    return 0;
}

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(char ch)
{
    if (is_full()) {
        printf("Stack Overflow");
        exit(EXIT_FAILURE);
    } else
        contents[top++] = ch;
}

char pop(void)
{
    if (is_empty()) {
        printf("Stack Underflow");
        exit(EXIT_FAILURE);
    } else
        return contents[--top];
}