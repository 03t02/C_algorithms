struct stack {
    int number;
    struct stack *next;
} stack;

void push(struct stack **list, int number);
void printStack(struct stack *list);
struct stack *pop(struct stack **list);
struct stack *search(struct stack *list, int number);

