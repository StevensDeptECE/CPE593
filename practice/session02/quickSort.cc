//@author yang bai
#include<iostream>
#include<vector>
using namespace std;

void quickSort(vector<int>& array, int low, int high) {
  if (low >= high) {
    return;
  }
  int pivot = array[low] + (array[high] - array[low]) / 2;
  int i = low, j = high;
  
  while(i <= j) {
    while(i <= j && array[i] < pivot) i++;
    while(i <= j && array[j] > pivot) j--;
    if(i <= j) {
      swap(array[i], array[j]);
      i++; j--;
    }
  }
  quickSort(array, low, j);
  quickSort(array, i, high);
}

int main() {
  vector<int> a;
  for(int i = 5; i >= 0; i--) a.push_back(i);
  quickSort(a, 0, a.size() - 1);
  for (auto i : a) {
    cout << i << '\t';
  }
}
