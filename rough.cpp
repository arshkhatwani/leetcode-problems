#include <bits/stdc++.h>
using namespace std;

int getPeak(vector<int> &a)
{
    int low = 0, high = a.size() - 1;
    int mid;

    while (low < high)
    {
        mid = low + (high - low) / 2;
        if (a[mid] < a[mid + 1])
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

bool validMountainArray(vector<int> &a, int low, int high)
{
    int i, j;
    bool upHill = false, downHill = false;

    for (i = low; i < high; i++)
    {
        if (a[i] == a[i + 1])
            return false;
        else if (a[i] < a[i + 1])
            upHill = true;
        else if (a[i] > a[i + 1])
            break;
    }

    for (j = i; j < high; j++)
    {
        if (a[j] <= a[j + 1])
            return false;
        else
            downHill = true;
    }

    return upHill and downHill;
}

int main()
{
    // vector <int> a = {2,1,4};
    // vector <int> a = {1,2,3,4};
    // vector<int> a = {4, 8, 3, 2, 1};
    // vector <int> a = {2,1};
    // vector<int> a = {2, 1, 4, 7, 3, 2, 5};

    // int peak = getPeak(a);

    // cout << peak << endl;
    // cout << a[peak] << endl;

    vector <int> a = {2,1,4,7,3,2,5};

    cout << validMountainArray(a, 1, 5) << endl;

    return 0;
}