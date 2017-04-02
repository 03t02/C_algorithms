# Simple linked list

**Simple linked list** is a kind of array, but much more flexible. With a classic array, you can only insert a new element at the end of this one. If you want to insert a new element at the middle of an array or at the beginning, you have to realloc a new array, loop through your old array to copy your data, and then insert your new value into the right place.

With *linked list* you don't have to do that. If you want to insert a new element at the end (tail)/ at the beginning (head), or even that a precise position of the list, you can do that very easily without realloc a new list.

Different with a classic array. You can't access to your data with the index, your data aren't store continuously in the memory. Each element of your linked list, also called `node` point to the next node by a pointer. If the next pointer of the current node is `NULL`, that means you are at the end of the list.

# Insert

Insertion in linked list is really simple.

###### Insert head

First, we create a new node with all information that we need. We set the number to your `new_node` number. And set the next pointer to `NULL`. If our `list` is `NULL`, that means the list is empty, so we have nothing to do, to set our `new_node` to our `list`. Otherwise, we set the next pointer of our `new_node` to `list`, and `new_node` is your new pointer for the beginning of the list.

##### C implementation

```C
void insertHead(struct ll **list, int number) {
    struct ll *new_node = NULL;

    new_node = malloc(sizeof(*new_node));
    new_node->number = number;
    new_node->next = NULL;

    if (*list == NULL) {
        *list = new_node;
    } else {
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

    if (*list == NULL) {
        *list = new_node;
    } else {
        struct ll *it = *list;
        while (it->next != NULL) {
            it = it->next;
        }
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

    while (it->next != NULL && it->next->next != NULL) {
        it = it->next;
    }
    it->next = NULL;
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
| Type            | Average case | Worst case |
|-----------------|--------------|------------|
| **Search**      | O(n)         | O(n)       |
| **Insert**      | O(n)         | O(n)       |
| **Delete**      | O(n)         | O(n)       |
| **Insert head** | O(1)         | O(1)       |
| **Delete head** | O(1)         | O(1)       |


# Example
```C
int main() {
    struct ll *list = NULL;
    struct ll *found_node = NULL;

    insertTail(&list, 5);
    insertTail(&list, 8);
    insertHead(&list, 4);
    insertHead(&list, 3);
    insertTail(&list, 29);
    insertTail(&list, 54);

    deleteHead(&list);
    deleteTail(&list);

    found_node = searchNode(list, 4);
    if (found_node != 0x0) {
        printf("Found: %d\n", found_node->number);
    }
    printList(list);
    return 0;
}
```

###### Output
```C
Found: 4
4
5
8
29
```