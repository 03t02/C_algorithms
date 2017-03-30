#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main() {
    struct bst *tree = NULL;

    push(&tree, 6);
    push(&tree, 4);
    push(&tree, 9);
    push(&tree, 5);

    printf("%d\n", tree->number);
    printf("%d\n", tree->left->number);
    printf("%d\n", tree->right->number);
    printf("%d\n", tree->left->right->number);

    return 0;
}
