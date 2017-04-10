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
