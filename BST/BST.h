typedef struct bst {
    int number;
    struct bst *left;
    struct bst *right;
} t_bst;

void invertTree(t_bst **tree);
void push(t_bst **tree, int number);
void inOrderTraversal(t_bst *tree);
void preOrderTraversal(t_bst *tree);
void postOrderTraversal(t_bst *tree);
t_bst *search(t_bst *tree, int number);
