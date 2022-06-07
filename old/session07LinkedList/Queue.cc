#include <list>
using namespace std;

class Queue {
    private:
    list<int> impl;
    public:
        Queue() : impl() {}
        void enqueue(int v) {
            impl.push_front(v); //O(1)
        }

        int dequeue() {
            int v = impl.front();
            impl.pop_back(); //O(n) slow. Why?
            return v;
        }

        bool isEmpty() {
            return impl.empty();
        }
}