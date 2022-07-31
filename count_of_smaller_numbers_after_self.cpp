#include <bits/stdc++.h>
using namespace std;

/*
Logic for increasing order merge sort
The process is to merge sort the array and while merging if the left array's element is greater than right array's element then we increment a count variable (initialised it to 0)
And when putting the element from left array in the merged array we add that count variable to the final counts array (this will be done even when there are elements left in the left array and we run a separate while loop for individual arrays in merge function)

We know that if an element 'x' in left array is greater than element 'y' in right array then every element after 'x' will also be greater than 'y' as both arrays are sorted, this is the intuition we use to solve the problem

Logic for decreasing order merge sort
https://youtu.be/_sA1xI4XK0c
*/

// merge sort in increasing order
class Solution
{
    vector<int> counts;
    void merge(vector<pair<int, int>> &arr, int low, int mid, int high)
    {
        vector<pair<int, int>> a, b;

        for (int i = low; i <= mid; i++)
        {
            a.push_back(arr[i]);
        }
        for (int i = mid + 1; i <= high; i++)
        {
            b.push_back(arr[i]);
        }

        int i = 0, j = 0, k = low;
        int m = a.size(), n = b.size();

        int count = 0;

        while (i < m and j < n)
        {
            if (a[i].first <= b[j].first)
            {
                counts[a[i].second] += count;
                arr[k++] = a[i++];
            }
            else
            {
                arr[k++] = b[j++];
                count++;
            }
        }

        while (i < m)
        {
            counts[a[i].second] += count;
            arr[k++] = a[i++];
        }

        while (j < n)
        {
            arr[k++] = b[j++];
        }
    }

    void mergeSort(vector<pair<int, int>> &a, int low, int high)
    {
        if (low < high)
        {
            int mid = low + (high - low) / 2;

            mergeSort(a, low, mid);
            mergeSort(a, mid + 1, high);

            merge(a, low, mid, high);
        }
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<pair<int, int>> arr;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            arr.push_back({nums[i], i});
        }

        counts = vector<int>(n, 0);

        mergeSort(arr, 0, nums.size() - 1);

        return counts;
    }
};

// merge sort decreasing order
class Solution
{
    vector<int> counts;
    void merge(vector<pair<int, int>> &arr, int low, int mid, int high)
    {
        vector<pair<int, int>> a, b;

        for (int i = low; i <= mid; i++)
        {
            a.push_back(arr[i]);
        }
        for (int i = mid + 1; i <= high; i++)
        {
            b.push_back(arr[i]);
        }

        int i = 0, j = 0, k = low;
        int m = a.size(), n = b.size();

        while (i < m and j < n)
        {
            if (a[i].first <= b[j].first)
            {
                arr[k++] = b[j++];
            }
            else
            {
                counts[a[i].second] += n - j;
                arr[k++] = a[i++];
            }
        }

        while (i < m)
        {
            arr[k++] = a[i++];
        }

        while (j < n)
        {
            arr[k++] = b[j++];
        }
    }

    void mergeSort(vector<pair<int, int>> &a, int low, int high)
    {
        if (low < high)
        {
            int mid = low + (high - low) / 2;

            mergeSort(a, low, mid);
            mergeSort(a, mid + 1, high);

            merge(a, low, mid, high);
        }
    }

public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<pair<int, int>> arr;
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            arr.push_back({nums[i], i});
        }

        counts = vector<int>(n, 0);

        mergeSort(arr, 0, nums.size() - 1);

        return counts;
    }
};

int main()
{

    return 0;
}