/**
 * Created by Linus Zhang on 2021/8/18.
 */

#ifndef LEARN_C_STACKADT_H
#define LEARN_C_STACKADT_H

#include <stdbool.h>

typedef struct stack_type *Stack;

Stack create(void);

void destroy(Stack s);

void make_empty(Stack s);

bool is_empty(Stack s);

bool is_full(Stack s);

void push(Stack s, int i);

int pop(Stack s);

#endif //LEARN_C_STACKADT_H
