struct bst {
    int number;
    struct bst *left;
    struct bst *right;
} bst;

void push(struct bst **tree, int number);
struct bst *search(struct bst *tree, int number);
