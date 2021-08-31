/**
 * Created by Linus Zhang on 2021/8/21.
 */
#include <stdio.h>
#include "queue.h"

int main(void)
{
    Queue q = create();
    offer(q, 1);
    offer(q, 2);
    offer(q, 3);
    offer(q, 4);
    offer(q, 5);
    offer(q, 6);
    offer(q, 7);
    offer(q, 8);
    offer(q, 9);
    offer(q, 10);

    printf("%d\n", peek(q));
    printf("%d\n", peek_last(q));

    poll(q);
    poll(q);
    poll(q);

    printf("%d\n", peek(q));
    printf("%d\n", peek_last(q));

    offer(q, 11);
    offer(q, 12);

    printf("%d\n", peek(q));
    printf("%d\n", peek_last(q));
}