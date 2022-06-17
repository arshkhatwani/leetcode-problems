#include <bits/stdc++.h>
using namespace std;

// Logic is like Russian Doll Envelopes Problem
// Watch video to understand logic: https://youtu.be/on2hvxBXJH4

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> a;
    a.push_back(arr[0]);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > a[a.size() - 1])
        {
            a.push_back(arr[i]);
        }
        else
        {
            auto itr = lower_bound(a.begin(), a.end(), arr[i]);
            *itr = arr[i];
        }
    }

    return a.size();
}

int main()
{

    return 0;
}