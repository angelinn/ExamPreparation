bool member(int x, int a[], int size)
{
    if (size == 0)
        return false;

    return a[size / 2] == x || 
          (a[size / 2] < x && member(x, a + size / 2, size / 2)) || 
          (member(x, a, size / 2));
}