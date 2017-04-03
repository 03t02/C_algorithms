typedef struct ll {
    int number;
    struct ll *next;
} t_ll;

void insertTail(t_ll **list, int number);
void insertHead(t_ll **list, int number);
void deleteHead(t_ll **list);
void deleteNode(t_ll *list, int number);
void deleteTail(t_ll **list);
void printList(t_ll *list);

t_ll *searchNode(t_ll *list, int number);
