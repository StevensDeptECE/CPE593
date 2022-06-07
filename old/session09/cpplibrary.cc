#include <iostream>
#include <forward_list>
using namespace std;

int main() {
  forward_list<int> a;
  for (int i = 0; i < 10; i++)
    a.push_front(i);

  for (forward_list<int>::iterator i = a.begin(); i != a.end(); ++i)
    cout << *i;
}
