#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "BST.h"

int main() {
    struct bst *tree = NULL;
    struct bst *found_node = malloc(sizeof(*found_node));

    int nbr[10] = {54, 65 ,87 ,23, 53, 32, 13, 53, 98, 34};

    for (int i = 0; i < 10; ++i) {
        push(&tree, nbr[i]);
    }

    found_node = search(tree, 53);
    printf("%d\n", found_node->number);
    printf("%d\n", found_node->left->number);
    printf("%d\n", found_node->right->number);
    return 0;
}
