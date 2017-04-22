#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

void invertTree(t_bst **tree) {
    if (*tree != NULL) {
        t_bst *tmp = (*tree)->left;

        (*tree)->left = (*tree)->right;
        (*tree)->right = tmp;

        invertTree(&(*tree)->left);
        invertTree(&(*tree)->right);
    }
}

void push(t_bst **tree, int number) {
    if (*tree == NULL) {
        t_bst *new_node = NULL;

        new_node = malloc(sizeof(*new_node));
        new_node->number = number;
        new_node->left = NULL;
        new_node->right = NULL;

        *tree = new_node;
    } else {
        if (number < (*tree)->number) {
            push(&(*tree)->left, number);
        } else if (number >= (*tree)->number) {
            push(&(*tree)->right, number);
        }
    }
}

void inOrderTraversal(t_bst *tree) {
    if (tree != NULL) {
        inOrderTraversal(tree->left);
        printf("%d ", tree->number);
        inOrderTraversal(tree->right);
    }
}

void preOrderTraversal(t_bst *tree) {
    if (tree != NULL) {
        printf("%d ", tree->number);
        preOrderTraversal(tree->left);
        preOrderTraversal(tree->right);
    }
}

void postOrderTraversal(t_bst *tree) {
    if (tree != NULL) {
        postOrderTraversal(tree->left);
        postOrderTraversal(tree->right);
        printf("%d ", tree->number);
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

