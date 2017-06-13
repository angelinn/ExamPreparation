bool member(int x, int a[], int size)
{
    if (size == 0)
        return false;

    return a[size / 2] == x || 
          (a[size / 2] < x && member(x, a + size / 2, size / 2)) || 
          (member(x, a, size / 2));
}

void selectionSort(int* nums, int N)
{
    for (int i = 0; i < N; ++i) 
    {
        int min = i;

        for (int j = i + 1; j < N; ++j) 
        {
            if (nums[j] < nums[min])
                min = j;
        }

        if (min != i) 
        {
            int x = nums[i];
            nums[i] = nums[min];
            nums[min] = x;
        }
    }
}