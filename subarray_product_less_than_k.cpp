#include <bits/stdc++.h>
using namespace std;

// Here to count subarrays inside subarray we are adding the length of it because all the subarrays inside a subarray will also satisfy the product condition

int numSubarrayProductLessThanK(vector<int> &a, int k)
{
    int n = a.size();
    int i = 0, j = 0, count = 0;
    int pro = a[i];

    while (j < n and i < n)
    {
        if (pro < k)
        {
            count += (j - i) + 1;
            j++;
            if (j != n)
                pro *= a[j];
        }
        else
        {
            pro /= a[i];
            i++;
        }
    }
    return count;
}

int main()
{

    return 0;
}