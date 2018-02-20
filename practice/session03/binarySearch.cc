#include <iostream>
#include <vector>

using namespace std;

int binarySearch(int* arr, int len, int target) {
  int left = 0;
  int right = len - 1;
  while(left + 1 < right) {
    int mid = left + (right - left) / 2;
    if(target < arr[mid]) {
      right = mid;
    }else if(target > arr[mid]) {
      left = mid;
    }else {
      return mid;
    }
  }

  if(arr[left] == target) return left;
  if(arr[right] == target) return right; 
}
