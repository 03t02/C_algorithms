# Stack

**Stack** is a data structure very similar to an *array*, but this one has a limited functionality. With a stack, you can only push an item at the end of the stack. And you can only remove the last item of the stack.

**Example:** We have an empty stack here, we call it `newStack`.

We want to push a new number into my `newStack` variable.

```C
push(newStack, 1);
// Here we have 1 in our newStack. Let's push some other numbers.

push(newStack, 2);
push(newStack, 3);
push(newStack, 4);
push(newStack, 5);
push(newStack, 6);
// Here what our newStack looks like. [1, 2, 3, 4, 5, 6]


pop(newStack);
// Here what our newStack looks like. [1, 2, 3, 4, 5]
```

# Insert

First we create a new node (`new_node`). We assign the number to our `new_node`. And the next to `NULL` (for now).

If our stack is `NULL` (empty). We assign our `new_node` to our stack, because it's the first element.

```C
	*list = new_node;
```

Otherwise, we add our `new_node` to the head of our list. Because we want to keep `O(1)` of time complexity.

```C
	new_node->next = *list;
	*list = new_node;
```

##### C implementation

```C
void push(struct stack **list, int number) {
    struct stack *new_node = NULL;

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

# Delete
##### C implementation

```C
struct stack *pop(struct stack **list) {
    if (list == NULL) {
        return NULL;
    }
    struct stack *node = *list;
    struct stack *head = (*list)->next;
    (*list)->next = NULL;
    *list = head;
    return node;
}
```

# Search

##### C implementation

```C
struct stack *search(struct stack *list, int number) {
    if (list == NULL) {
        return NULL;
    }

    if (list->number == number) {
        return list;
    }
    return search(list->next, number);
}
```

# The complexity in Big O Notation
###### Time Complexity
| Type       | Average case | Worst case |
|------------|--------------|------------|
| **Search** | O(n)         | O(n)       |
| **Insert** | O(1)         | O(1)       |
| **Delete** | O(1)         | O(1)       |
