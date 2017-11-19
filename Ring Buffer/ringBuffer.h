typedef struct RingBuffer {
    int write;
    int read;
    int *data;
    int dataSize;
} RingBuffer;

void initRingBuffer(RingBuffer **buffer, int dataSize);
void writeBuffer(RingBuffer **buffer, int data);
int readBuffer(RingBuffer **buffer);
