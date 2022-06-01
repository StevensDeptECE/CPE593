void quicksort(int x[], int L, int R) {
  if (R <= L)
    return;
  int pivot = (x[L] + x[R]) / 2;
  int i = L, j = R;


  while (i < j) {
    while (x[i]< pivot)
      i++;
    while(x[j] >= pivot)
      j--;
    swap(x[i], x[j]);
  }
  // guaranteed i == j
  quicksort(x, L, i);
  quicksort(x, i+1, R);
}

//faster (lower constant)
void fasterRecursionquicksort(int x[], int L, int R) {
  int pivot = (x[L] + x[R]) / 2;
  int i = L, j = R;


  while (i < j) {
    while (x[i]< pivot)
      i++;
    while(x[j] >= pivot)
      j--;
    swap(x[i], x[j]);
  }
  // guarateed i == j
  if (i - L >= k)
    quicksort(x, L, i);
  if (R - (i+1) > k)
    quicksort(x, i+1, R);
}

void knuthquicksort(int a[], int n) {
  fasterquicksort(a, 0, n-1);
  insertionSort(a);
}

#if 0
for (int i = L; i < R; i++) {
    if (x[i] > pivot) {
      for (; j > L; j--)
#endif


	
int main() {
  int[] a = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  //  quicksort(a, 0, 9);
  knuthquicksort(a);
