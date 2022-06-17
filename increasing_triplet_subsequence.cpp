#include <bits/stdc++.h>
using namespace std;

// Logic: https://youtu.be/yEFlGWOVH8g

bool increasingTriplet(vector<int> &a)
{
    int n = a.size();
    int i, j, k;
    i = j = k = INT_MAX;
    for (int idx = 0; idx < n; idx++)
    {
        if (a[idx] <= i)
        {
            i = a[idx];
        }
        else if (a[idx] <= j)
        {
            j = a[idx];
        }
        else
            return true;
    }
    return false;
}

int main()
{

    return 0;
}