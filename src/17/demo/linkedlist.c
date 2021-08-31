/**
 * Created by Linus Zhang on 2021/8/15.
 */

#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

struct node *add_to_list(struct node *list, int n)
{
    struct node *new_node;

    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = list;
    return new_node;
}

struct node *search_list(struct node *list, int n)
{
    while (list != NULL && list->value != n) {
        list = list->next;
    }
    return list;
}

struct node *delete_from_list(struct node *list, int n)
{
    struct node *curr, *prev;

    for (curr = list, prev = NULL;
         curr != NULL && curr->value != n;
         prev = curr, curr = curr->next);

    // not fount;
    if (curr == NULL)
        return list;

    // first node
    if (prev == NULL)
        list = list->next;
    else
        prev->next = curr->next;
    free(curr);
    return list;
}