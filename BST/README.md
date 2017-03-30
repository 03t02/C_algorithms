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

# Insertion
When we insert a new value in the tree, we compare the current value to the root value, if the current value is smaller than the root value, then we move to the left node, if the current value is bigger than the root value, then we move to the right node.

We have an array of number `int nbr[3] = {5, 4, 8, 1};`

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
		   /  \
		  /    \
	    [4]    [8]
```

###### And finallt, we gonna try to to insert number 1 in our tree.

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
		   /  \
		  /    \
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


# Deletion

# Search

# The complexity in Big O Notation
###### Time Complexity
| Type       | Best case | Average case | Worst case |
|------------|-----------|--------------|------------|
| **Insert** | O(1)      | O(log n)     | O(n)       |
| **Delete** | O(1)      | O(log n)     | O(n)       |
| **Search** | O(1)      | O(log n)     | O(n)       |

## TODO
- [X] Insert

- [X] Search

- [ ] Delete

- [ ] In order traversal

- [ ] Pre order traversal

- [ ] Post order traversal
