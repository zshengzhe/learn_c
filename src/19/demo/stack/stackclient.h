/**
 * Created by Linus Zhang on 2021/8/18.
 */

#ifndef LEARN_C_STACKCLIENT_H
#define LEARN_C_STACKCLIENT_H

#include <stdbool.h>

void make_empty(void);

bool is_empty(void);

bool is_full(void);

void push(int i);

int pop(void);

#endif //LEARN_C_STACKCLIENT_H
