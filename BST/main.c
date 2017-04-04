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

    found_node = search(tree, 91);
    printf("%d\n", found_node->number);
    printf("\n===============\n");
    inOrderTraversal(tree);
    printf("\n===============\n");
    preOrderTraversal(tree);
    printf("\n===============\n");
    postOrderTraversal(tree);
    printf("\n");
    return 0;
}
