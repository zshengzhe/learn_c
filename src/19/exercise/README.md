### 19.1

#### 1

### 19.2

#### 2

```c
#include <stdio.h>
#include <stdlib.h>
#include "stackclient.h"

#define PUBLIC
#define PRIVATE static

struct node {
    int data;
    struct node *next;
};

PRIVATE struct node *top = NULL;

PRIVATE void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

PUBLIC void make_empty(void)
{
    while (!is_empty())
        pop();
}

PUBLIC bool is_empty(void)
{
    return top == NULL;
}

PUBLIC bool is_full(void)
{
    return false;
}

PUBLIC void push(int i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: stack is full");

    new_node->data = i;
    new_node->next = top;
    top = new_node;
}

PUBLIC int pop(void)
{
    if (is_empty())
        terminate("Error in pop: stack is empty.");
    struct node *old_node = top;
    int data = old_node->data;
    top = old_node->next;
    free(old_node);
    return data;
}
```

#### 3


