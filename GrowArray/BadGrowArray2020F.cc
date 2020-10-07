#include <cstring>
class BadGrowArray {
    private:
        int capacity;
        int* data;
    public:
        BadGrowArray() : capacity(0), data(nullptr) {}
        void insert(int v, int i){ //O( n )
            int* old = data; // first point at the old
            data = new int[capacity + 1]; //O(1)
            memcpy(&data[0], &old[0], i - 1);    //O(n)
            memcpy(&data[i + 1], &old[i], capacity - i);
            data[i] = v;
            delete[] old; //required or you will leak data
            capacity++;
        }
        void addEnd(int v){ //O( n )
            int* old = data; // first point at the old
            data = new int[capacity + 1];
            memcpy(&data[0], &old[0], capacity);
            data[capacity] = v;
            delete[] old;
            capacity++;
        }
        void addStart(int v){ //O( n )
            int* old = data; // first point at the old
            data = new int[capacity + 1];
            memcpy(&data[1], &old[0], capacity);
            data[0] = v;
            delete[] old;
            capacity++;
        }
};