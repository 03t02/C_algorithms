# Double linked list

**Double linked list** is another form of *linked list*. If you don't know what a linked list is. Please read [this](https://github.com/03t02/C_algorithms/tree/master/Linked%20List) first.

The only different between a **simple linked list** and a **double linked list** is the double linked list has two pointers, instead of one. Simple linked list has one pointer that is the next element of the list. And the double linked list has two pointers, one is the pointer to the next element of the list, and one is the pointer to the previous element of the list.

# Insert

Insertion in linked list is really simple.

###### Insert head

First, we create a new node with all information that we need. We set the number to your `new_node` number. And set the next and the prev pointer to `NULL`. If our `list` is `NULL`, that means the list is empty, so we have nothing to do, to set our `new_node` to our `list`. Otherwise, we set the previous pointer of our list to `new_node` (because our `*list` pointer became the 2nd element of the list). We set the next pointer of our `new_node` to `list`, and `new_node` is your new pointer for the beginning of the list.

##### C implementation

```C
void insertHead(struct ll **list, int number) {
    struct ll *new_node = NULL;

    new_node = malloc(sizeof(*new_node));
    new_node->number = number;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*list == NULL) {
        *list = new_node;
    } else {
        (*list)->prev = new_node;
        new_node->next = *list;
        *list = new_node;
    }
}
```

###### Insert tail

The step to insert if the `list` is empty, is the same as the insert head function.

But if our linked list is not `NULL`. We have to loop over the list until we reach at the end of this one.
And then insert the `new_node` to our last element (here `it->next`).

##### C implementation

```C
void insertTail(struct ll **list, int number) {
    struct ll *new_node = NULL;

    new_node = malloc(sizeof(*new_node));
    new_node->number = number;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*list == NULL) {
        *list = new_node;
    } else {
        struct ll *it = *list;
        while (it->next != NULL) {
            it = it->next;
        }
        new_node->prev = it;
        it->next= new_node;
    }
}
```

# Delete
###### Delete head
Delete an element at the beginning of the list is really easy, and it takes `O(1)` of time complexity. To do that, we have to disconnect our `next` pointer of the first element to `NULL`.

##### C implementation

```C
void deleteHead(struct ll **list) {
    struct ll *head = (*list)->next;

    (*list)->next = NULL;
    *list = head;
}
```

###### Delete tail
Delete an element at the end of the list, it takes `O(n)` time complexity. Because we have to loop over the list, reach to the end of list one to remove it.

##### C implementation

```C
void deleteTail(struct ll **list) {
    struct ll *it = *list;

    while (it->next != NULL) {
        it = it->next;
    }
    it->prev->next = NULL;
}
```

# Search
Search for an element in a list, it also takes `O(n)` time complexity.

##### C implementation

```C
struct ll *searchNode(struct ll *list, int number) {
    if (list == NULL) {
        return NULL;
    }
    if (list->number == number) {
        return list;
    }
    return searchNode(list->next, number);
}
```

# The complexity in Big O Notation
###### Time Complexity
| Type            | Worst case |
|-----------------|------------|
| **Search**      | O(n)       |
| **Insert**      | O(n)       |
| **Delete**      | O(n)       |
