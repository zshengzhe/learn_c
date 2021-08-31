/**
 * Created by Linus Zhang on 2021/8/19.
 */

#ifndef LEARN_C_STACKADT2_H
#define LEARN_C_STACKADT2_H

#include <stdbool.h>

typedef int Item;

typedef struct stack_type *Stack;

Stack create(int size);

void destroy(Stack s);

void make_empty(Stack s);

bool is_empty(Stack s);

bool is_full(Stack s);

void push(Stack s, Item i);

Item pop(Stack s);

#endif //LEARN_C_STACKADT2_H
