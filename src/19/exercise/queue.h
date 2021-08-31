/**
 * Created by Linus Zhang on 2021/8/19.
 */

#ifndef LEARN_C_QUEUE_H
#define LEARN_C_QUEUE_H

#include <stdbool.h>

typedef int Item;

typedef struct queue_type *Queue;

Queue create(void);

void offer(Queue q, Item i);

Item poll(Queue q);

Item peek(Queue q);

Item peek_last(Queue q);

bool is_empty(Queue q);

#endif //LEARN_C_QUEUE_H
