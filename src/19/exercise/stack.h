/**
 * Created by Linus Zhang on 2021/8/21.
 */

#ifndef LEARN_C_STACK_H
#define LEARN_C_STACK_H

typedef int Item;

typedef struct stack_type *Stack;

Stack create(void);

void destroy(Stack s);

void make_empty(Stack s);

bool is_empty(const Stack s);

bool is_full(const Stack s);

void push(Stack s, Item i);

Item pop(Stack s);

#endif //LEARN_C_STACK_H
