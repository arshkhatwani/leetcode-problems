#include <bits/stdc++.h>
using namespace std;

/*
Problem link: https://www.codingninjas.com/codestudio/problems/count-inversions_615
*/

long long merge(long long *arr, int l, int m, int r)
{
    long long count = 0;
    int l1 = m - l + 1, l2 = r - m;
    int a[l1], b[l2];

    for (int i = 0; i < l1; i++)
    {
        a[i] = arr[l + i];
    }
    for (int i = 0; i < l2; i++)
    {
        b[i] = arr[m + 1 + i];
    }

    int i = 0, j = 0, k = l;

    while (i < l1 and j < l2)
    {
        if (a[i] <= b[j])
        {
            arr[k++] = a[i++];
        }
        else
        {
            count += l1 - i;
            arr[k++] = b[j++];
        }
    }
    while (i < l1)
    {
        arr[k++] = a[i++];
    }
    while (j < l2)
    {
        arr[k++] = b[j++];
    }

    return count;
}
long long mergeSort(long long *arr, int l, int r)
{
    long long count = 0;
    if (l < r)
    {
        int m = (l + r) / 2;

        count += mergeSort(arr, l, m);
        count += mergeSort(arr, m + 1, r);

        count += merge(arr, l, m, r);
    }
    return count;
}

long long getInversions(long long *arr, int n)
{
    long long count = mergeSort(arr, 0, n - 1);
    return count;
}

int main()
{

    return 0;
}