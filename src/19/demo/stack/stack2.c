/**
 * Created by Linus Zhang on 2021/8/18.
 */

#include <stdio.h>
#include <stdlib.h>
#include "stackclient.h"

struct node {
    int data;
    struct node *next;
};

static struct node *top = NULL;

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(void)
{
    while (!is_empty())
        pop();
}

bool is_empty(void)
{
    return top == NULL;
}

bool is_full(void)
{
    return false;
}

void push(int i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: stack is full");

    new_node->data = i;
    new_node->next = top;
    top = new_node;
}

int pop(void)
{
    if (is_empty())
        terminate("Error in pop: stack is empty.");
    struct node *old_node = top;
    int data = old_node->data;
    top = old_node->next;
    free(old_node);
    return data;
}
