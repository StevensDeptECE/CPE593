class CircularBuffer {
private:
   int* buffer;
   uint32_t capacity;
   void grow() {}
   uint32_t head, tail;
public:
    CircularBuffer(int capacity) : buffer(new int[capacity]), capacit(capacity) {
        head = tail = 0;
    }
    void enqueue(int v) {
        buffer[tail++] = v;
        // if tail goes beyond end, start at 0 again
        // if tail becomes = head, FULL (grow)
    }
    int dequeue() {}
    bool isEmpty() {}
};