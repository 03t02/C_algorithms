typedef struct stack {
    int number;
    struct stack *next;
} t_stack;

void push(t_stack **list, int number);
void printStack(t_stack *list);
struct stack *pop(t_stack **list);
struct stack *search(t_stack *list, int number);

