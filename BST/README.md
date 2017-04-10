# Binary search tree (BST)

**Binary Search Tree (BST)** is also called **Sorted Binary Trees**.

**BST** is a particular data structure, that we can store any kind of type (numbers, characters, strings, or other structure...).

Each node of the tree can only have maximum **2** childrens (left node, and right node).

## Structure in C
In this example, we gonna have a very basic C structure.

We store a number in this structure, the left node, and the right node.

```C
struct bst {
    int number;
    struct bst *left;
    struct bst *right;
} bst;
```

# Insert
When we insert a new value in the tree, we compare the current value to the root value, if the current value is smaller than the root value, then we move to the left node, if the current value is bigger than the root value, then we move to the right node.

We have an array of number `int nbr[4] = {5, 4, 8, 1};`

###### Now we gonna try to to insert number 5 in our tree.

* Our tree is empty, so 5 is the root node.

```
            [5]
```

###### And we gonna try to to insert number 4 in our tree.

* We compare 4 with the root's value (5)
* 4 < 5
* So we know that we have to move to the left node.
* We check if there is something at the root's left node.
* It's empty
* So we insert 4 value to the root's left node.

```
           [5]
           /
          /
        [4]
```
###### And we gonna try to to insert number 8 in our tree.

* We compare 8 with the root's value (5)
* 8 > 5
* So we know that we have to move to the right node.
* We check if there is something at the root's right node.
* It's empty
* So we insert 8 value to the root's right node.

```
           [5]
           / \
          /   \
        [4]    [8]
```

###### And finally, we gonna try to to insert number 1 in our tree.

* We compare 1 with the root's value (5).
* 1 < 5.
* So we know that we have to move to the left node.
* We check if there is something at the root's left node.
* It's not empty.
* So we compare 1 to the root's left node (4).
* 1 < 4
* So we know that we have to move to the left node.
* We check if there is something at the root's left node.
* It's empty.
* So we insert 1 value here.


```
          [5]
          / \
         /   \
       [4]    [8]
       /
      /
    [1]
```

##### C implementation

```C
void push(struct bst **tree, int number) {
    struct bst *new_node = NULL;

    new_node = malloc(sizeof(*new_node));
    new_node->number = number;
    new_node->left = NULL;
    new_node->right = NULL;

    if (*tree == NULL) {
        *tree = new_node;
    } else {
        if (number < (*tree)->number) {
            push(&(*tree)->left, number);
        } else if (number >= (*tree)->number) {
            push(&(*tree)->right, number);
        }
    }
}
```

# Search
Let's take the list in our `insert` example: `int nbr[4] = {5, 4, 8, 1};`

We want to find the number `1`.

* 1 < 5
* Move to the left node.
* 1 < 4
* Move to the left node again.
* 1 = 1
* Found it.

##### C implementation

```C
struct bst *search(struct bst *tree, int number) {
    if (tree->number == number) {
        return tree;
    } else if (number < tree->number) {
        return search(tree->left, number);
    }
    return search(tree->right, number);
}
```

# Invert Tree
Inspired from **Max Howell**'s [tweet](https://twitter.com/mxcl/status/608682016205344768).

The algorithm to solve this problem is pretty simple. All you have to do is exchange the left and right pointer recursively.

The time complexity of this algorithm is **O(h)** where **h** is the **height** of the tree.

##### C implementation
```C
void invertTree(t_bst **tree) {
    if (*tree != NULL) {
        t_bst *tmp = (*tree)->left;

        (*tree)->left = (*tree)->right;
        (*tree)->right = tmp;

        invertTree(&(*tree)->left);
        invertTree(&(*tree)->right);
    }
}
```


# The complexity in Big O Notation
###### Time Complexity
| Type       | Best case | Average case | Worst case |
|------------|-----------|--------------|------------|
| **Insert** | O(1)      | O(log n)     | O(n)       |
| **Delete** | O(1)      | O(log n)     | O(n)       |
| **Search** | O(1)      | O(log n)     | O(n)       |

# Example
```C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BST.h"

int main() {
    t_bst *tree = NULL;
    t_bst *found_node = malloc(sizeof(*found_node));

    int nbr[12] = {54, 65 ,87 ,23, 77, 32, 13, 53, 98, 34, 84, 91};

    for (int i = 0; i < 12; ++i) {
        push(&tree, nbr[i]);
    }

    printf("Before invert\n");
    printf("root: %d\n", tree->number);
    printf("left: %d\n", tree->left->number);
    printf("right: %d\n", tree->right->number);

    invertTree(&tree);
    printf("After invert\n");
    printf("root: %d\n", tree->number);
    printf("left: %d\n", tree->left->number);
    printf("left left: %d\n", tree->left->left->number);
    printf("left left left: %d\n", tree->left->left->left->number);
    printf("left left left right: %d\n", tree->left->left->left->right->number);
    printf("right: %d\n", tree->right->number);

    return 0;
}
```

###### Output
```C
Before invert
root: 54
left: 23
right: 65
After invert
root: 54
left: 65
left left: 87
left left left: 98
left left left right: 91
right: 23
```