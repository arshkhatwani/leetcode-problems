#include <bits/stdc++.h>
using namespace std;

// Logic: https://youtu.be/rh2Bkul2zzQ

int longestMountain(vector<int> &a)
{
    int n = a.size();
    int j, ans = 0;

    for (int i = 1; i < n; i++)
    {
        j = i;
        bool flag = false;
        int count = 1;

        while (j < n and a[j] > a[j - 1])
        {
            j++;
            count++;
        }

        while (j != i and j < n and a[j] < a[j - 1])
        {
            j++;
            count++;
            flag = true;
        }

        if (i != j and flag and count > 2)
        {
            ans = max(ans, count);
            j--;
        }

        i = j;
    }

    return ans;
}

int main()
{

    return 0;
}