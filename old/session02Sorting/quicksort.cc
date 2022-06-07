 0//quicksort
/*
8  7  4  5  6  3  1  2
pivot = 4
         i     j
2                    8
   1              7
         3     5
2  1  4  3  6  5  7  8
         j   i

        O(n log n)
*/
void quicksort(int a[], int L, int R)
{
    // termination condition
    if (L >= R)
        return;

    int pivot = a[random(L, R)];
    int i = L, j = R;
    while (i < j)
    {
        while (i < j && a[i] <= pivot)
            i++;
        while (i < j && a[j] > pivot)
            j--;
        // what is true here?
        if (i < j)
        {
            swap(a[i], a[j]);
            i++, j--;
        }
    }
    quicksort(a, L, i - 1);
    quicksort(a, i, R);
}

//LOMUTO