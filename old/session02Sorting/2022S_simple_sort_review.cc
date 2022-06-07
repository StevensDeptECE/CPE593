// pseudocode
void bubblesort(int a[])
{
    for (int i = 0; i < a.length - 1; i++)
    {
        for (int j = a.length - 2 - i; j >= 0; j--)
        {
            if (a[j] > a[j + 1])
            {
                //swap
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}