#include <bits/stdc++.h>
using namespace std;

// This problem is same as count inversions problem in Striver SDE sheet with a little variation

class Solution
{
private:
    int merge(vector<int> &arr, int l, int m, int r)
    {
        int n1 = m - l + 1, n2 = r - m, count = 0;

        vector<int> a(n1), b(n2);

        for (int i = 0; i < n1; i++)
        {
            a[i] = arr[l + i];
        }
        for (int i = 0; i < n2; i++)
        {
            b[i] = arr[m + 1 + i];
        }

        int i = 0, j = 0, k = l;

        for (i = 0; i < n1; i++)
        {
            while (j < n2 and a[i] > 2LL * b[j])
            {
                j++;
            }
            count += j;
        }

        i = 0, j = 0;
        while (i < n1 and j < n2)
        {
            if (a[i] <= b[j])
            {
                arr[k++] = a[i++];
            }
            else
            {
                arr[k++] = b[j++];
            }
        }

        while (i < n1)
        {
            arr[k++] = a[i++];
        }
        while (j < n2)
        {
            arr[k++] = b[j++];
        }

        return count;
    }
    int mergeSort(vector<int> &arr, int l, int r)
    {
        int count = 0;
        if (l < r)
        {
            int m = (l + r) / 2;

            count += mergeSort(arr, l, m);
            count += mergeSort(arr, m + 1, r);

            count += merge(arr, l, m, r);
        }
        return count;
    }

public:
    int reversePairs(vector<int> &a)
    {
        int n = a.size();

        int count = mergeSort(a, 0, n - 1);

        return count;
    }
};

int main()
{

    return 0;
}