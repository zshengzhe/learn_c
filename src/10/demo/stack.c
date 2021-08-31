/**
 * Created by Linus Zhang on 2021/8/3.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE  100

void error_then_exit(const char *error);
void stack_overflow(void);
void stack_underflow(void);

// external variables
int contents[STACK_SIZE];
int top;

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

void push(int i)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = i;
}

int pop(void )
{
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}

void stack_overflow(void)
{
    error_then_exit("Stack Overflow");
}

void stack_underflow(void)
{
    error_then_exit("Stack Underflow");
}

void error_then_exit(const char *error)
{
    printf("%s", error);
    exit(EXIT_FAILURE);
}