/**
 * Created by Linus Zhang on 2021/8/15.
 */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node {
    int value;
    struct node *next;
};

struct node *add_to_list(struct node *list, int n);

struct node *search_list(struct node *list, int n);

struct node *delete_from_list(struct node *list, int n);

#endif // LINKEDLIST_H
