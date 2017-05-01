typedef struct queue {
    int number;
    struct queue *prev;
    struct queue *next;
} t_queue;

void enqueue(t_queue **list, int number);
void printQueue(t_queue *list);
void dequeue(t_queue **list);
t_queue *search(t_queue *list, int number);
