### 17.1

#### 1

```c
#include <stdlib.h>
#include <stdio.h>

void *my_malloc(size_t size)
{
    void *p = malloc(size);
    if (p == NULL) {
        printf("Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    return p;
}
```

### 17.2

#### 2

```c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *duplicate(char *str)
{
    int len = strlen(str);
    char *p = malloc(len + 1);
    if (p == NULL) {
        printf("Error: malloc failed");
        exit(EXIT_FAILURE);
    }

    strcpy(p, str);
    return p;
}
```

### 17.3

#### 3

```c
#include <stdlib.h>

int *create_array(int n, int initial_value)
{
    int *p;
    int *arr = malloc(n * sizeof(int));
    if (p == NULL) {
        printf("Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    for (p = arr; p < arr + n; p++) {
        *p = initial_value;
    }
    return arr;
}
```

### 17.5

#### 5

(a) p->b = ' '; illegal

(b) p->e[3]; legal

(c) (*p).d.a = 'a'; legal

(d) p->d.c = 20; legal

#### 6

```c
struct node *delete_from_list(struct node **list, int n)
{
    struct node *item = *list;
    while (item) {
        if (item->value == n) {
            *list = item->next;
            free(item);
            break;
        }
        list = &item->next;
        item = item->next;
    }
    return *list;
}
```

#### 7

```c
struct node *next_node;

while (p != NULL) {
    next_node = p->next;
    free(p);
    p = next_node;
}
```

#### 11

```c
struct node {
    int value;
    struct node *next;
};

int count_occurrences(struct node *list, int n)
{
    int r = 0;
    while(list != NULL) {
        if (list->value == n)
            r++;
        list = list->next;
    }
    return r;
}
```

#### 12

```c
struct node *find_last(struct node *list, int n)
{
    struct node result = NULL;
    while(list != NULL) {
        if (list->value == n)
            result = list;
        list = list->next;
    }
    return result;
}
```

### 17.6

#### 14

```c
void delete_from_list(struct node **list, int n)
{
    struct node *entry = *list;

    while (entry != NULL) {
        if (entry->value == n) {
            *list = entry->next;
            free(entry);
        }
        list = &entry->next;
        entry = entry->next;
    }
}
```