struct ll {
    int number;
    struct ll *next;
} ll;

void insertTail(struct ll **list, int number);
void insertHead(struct ll **list, int number);
void deleteHead(struct ll **list);
void deleteNode(struct ll *list, int number);
void deleteTail(struct ll **list);
void printList(struct ll *list);

struct ll *searchNode(struct ll *list, int number);
