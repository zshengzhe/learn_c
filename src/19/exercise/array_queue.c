/**
 * Created by Linus Zhang on 2021/8/21.
 */
#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

#define MAX_SIZE 10

struct queue_type {
    Item contents[MAX_SIZE];
    int head;
    int tail;
    int size;
};

void terminate(char *msg)
{
    printf("%s", msg);
    exit(EXIT_FAILURE);
}

bool is_full(Queue q)
{
    return q->size == MAX_SIZE;
}

Queue create(void)
{
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create: queue could not be created.");

    q->head = 0;
    q->tail = 0;
    q->size = 0;
    return q;
}

void offer(Queue q, Item i)
{
    if (is_full(q))
        terminate("Error in offer: queue is full.");

    q->contents[q->tail] = i;
    q->tail = (q->tail + 1) % MAX_SIZE;
    q->size++;
}

Item poll(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek: queue is empty.");

    Item data = q->contents[q->head];
    q->head = (q->head + 1) % MAX_SIZE;
    q->size--;
    return data;
}

Item peek(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek: queue is empty.");
    return q->contents[q->head];
}

Item peek_last(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek_last: queue is empty.");
    int t = q->tail - 1;
    return q->contents[t < 0 ? MAX_SIZE - 1 : t];
}

bool is_empty(Queue q)
{
    return q->size == 0;
}