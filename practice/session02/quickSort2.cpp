#include<iostream>
#include<vector>
using namespace std;
void quickSort(vector<int>& ls, int start, int end) {
  if(start >= end) return ;
  int pivot = ls[end];
  int store = start;
  int i = start;
  while(i < end) {
    if(ls[i] < pivot) {
      swap(ls[i], ls[store]);
      store++;
    }
    i++;
  }
  swap(ls[store],ls[i]);
  for (auto i : ls) {
    cout << i << '\t';
  }
  cout << '\n';
  quickSort(ls, start, store - 1);
  quickSort(ls, store + 1, end);
}
int main() {
  vector<int> a;
  for(int i = 5; i >= 0; i--) a.push_back(i);
  quickSort(a, 0, a.size() - 1);
  for (auto i : a) {
    cout << i << '\t';
  }
}
