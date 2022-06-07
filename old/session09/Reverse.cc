int main() {
  LinkedList a;
  for (int i = 0; i < 10; i++)
    a.addEnd(i);

  LinkedList b;
  for (LinkedList::Iterator i = a; !i; ++i)
    b.addStart(*i);
}
