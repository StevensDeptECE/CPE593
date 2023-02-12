#include "LinkedList.hh"

class Stack1 {
private:
  LinkedList impl;
public:
  Stack1() : impl() {} // O(1)
  void push(int v) { //O(1)
    impl.addStart(v);
  }
  int pop() { // O(1)
    return impl.removeStart();
  }
  bool isEmpty() const { //O(1)
    return impl.isEmpty();
  }
};

class Stack2 {
private:
  DynamicArray impl;
public:
  Stack2(int capacity) : impl(capacity)) {} // O(1)
  void push(int v) { //O(1)
    impl.addEnd(v);
  }
  int pop() { // O(1)
    return impl.removeEnd();
  }
  bool isEmpty() const { //O(1)
    return impl.isEmpty();
  }
};



