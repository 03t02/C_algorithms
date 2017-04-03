typedef struct bst {
    int number;
    struct bst *left;
    struct bst *right;
} t_bst;

void push(t_bst **tree, int number);
t_bst *search(t_bst *tree, int number);
