#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int>& arr, int left, int mid, int right){
  int i = left, j = mid + 1, k = left;
  int sz = arr.size();
  vector<int> b(sz);
  while(i <= mid && j <= right) {
    if(arr[i] <= arr[j]){
      b[k++] = arr[i++];
    } else {
      b[k++] = arr[j++];
    }
  }
  if(i > mid){
    for (int p = j; p <= right; p++){
      b[k++] = arr[p];
    }
  } else {
      for(int q = i; q <= mid; q++){
	b[k++] = arr[q];
      }
    }

  for(int h = left; h <= right; h++){
    arr[h] = b[h];
  }
}
void mergeSort(vector<int>& arr, int left, int right){
  if(left < right){
    int i = left + (right - left) / 2;
    mergeSort(arr, left, i);
    mergeSort(arr, i + 1, right);
    merge(arr, left, i, right);
  }
}

int main(){
  vector<int> arr = {89, 76, 58, 14, 45};
  mergeSort(arr, 0, arr.size() - 1);
  for(auto a : arr){
    cout << a << '\t';
  }
}
    
