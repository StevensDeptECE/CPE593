class LinkedList {
  class Node {
    int val;
    Node* next;
  };

  Node* head;
  Node* tail;
    
};

int main() {
  LinkedList2 a;
  const int n = 1000000;
  for (int i = 0; i < n; i++)
    a.addEnd(i); //O(n)

}
