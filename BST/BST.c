#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void push(t_bst **tree, int number) {
    t_bst *new_node = NULL;

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

t_bst *search(t_bst *tree, int number) {
    if (tree->number == number) {
        return tree;
    } else if (number < tree->number) {
        return search(tree->left, number);
    }
    return search(tree->right, number);
}

