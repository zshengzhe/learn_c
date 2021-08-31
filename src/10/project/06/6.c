/**
 * Created by Linus Zhang on 2021/8/3.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

#define STACK_SIZE 100

int contents[STACK_SIZE];
int top = 0;

void make_empty(void);

void push(int num);

int pop(void);

bool is_empty(void);

bool is_full(void);

int main(void)
{
    char ch;
    int n1, n2;
    printf("Enter an RPN expression: ");

    while ((ch = getchar()) != '\n') {
        if (isdigit(ch))
            push(ch - '0');
        else
            switch (ch) {
                case '+':
                    n2 = pop();
                    n1 = pop();
                    push(n1 + n2);
                    break;
                case '-':
                    n2 = pop();
                    n1 = pop();
                    push(n1 - n2);
                    break;
                case '*':
                    n2 = pop();
                    n1 = pop();
                    push(n1 * n2);
                    break;
                case '/':
                    n2 = pop();
                    n1 = pop();
                    push(n1 / n2);
                    break;
                case '=':
                    printf("Value of expression: %d\n", pop());
                    break;
                case ' ':
                    break;
                default:
                    exit(EXIT_FAILURE);
            }

    }
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

void push(int num)
{
    if (is_full()) {
        printf("Expression is too complex");
        exit(EXIT_FAILURE);
    } else
        contents[top++] = num;
}

int pop(void)
{
    if (is_empty()) {
        printf("Not enough operands in expression");
        exit(EXIT_FAILURE);
    } else
        return contents[--top];
}