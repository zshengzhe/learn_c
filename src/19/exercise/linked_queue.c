/**
 * Created by Linus Zhang on 2021/8/19.
 */
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct node {
    Item data;
    struct node *next;
};

struct queue_type {
    struct node *head;
    struct node *tail;
    int size;
};

void terminate(char *msg)
{
    printf("%s", msg);
    exit(EXIT_FAILURE);
}

Queue create(void)
{
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create: queue could not be created.");
    q->size = 0;
    return q;
}

void offer(Queue q, Item i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in offer: node could not be created.");
    new_node->data = i;
    // first node
    if (q->size == 0) {
        q->head = q->tail = new_node;
    }
        // other node
    else {
        q->tail->next = new_node;
        q->tail = new_node;
    }
    q->size++;
}

Item poll(Queue q)
{
    struct node *old_node = q->head;
    Item data = q->head->data;
    if (is_empty(q))
        terminate("Error in poll: queue is empty.");

    q->head = q->head->next;
    free(old_node);
    q->size--;

    if (q->size == 0) {
        q->tail = NULL;
    }
    return data;
}

Item peek(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek: queue is empty.");
    return q->head->data;
}

Item peek_last(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek_last: queue is empty.");
    return q->tail->data;
}

bool is_empty(Queue q)
{
    return q->size == 0;
}