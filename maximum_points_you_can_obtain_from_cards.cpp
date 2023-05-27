#include <bits/stdc++.h>
using namespace std;

/*
What if instead of picking up k cards we find a subarray of length (n - k) where n = size of array with the minimum sum possible

For finding cards with max score possible we have to find a subarray with min sum possible and then we can subtract that min sum from the total sum (of entire array) to get the max score possible

This can be done using sliding window, see the code to understand more.
LeetCode hints can also be referred.
*/

class Solution
{
public:
    int maxScore(vector<int> &a, int k)
    {
        int n = a.size(), minSum = 0, totalSum = 0;

        for (int i = 0; i < n; i++)
        {
            if (i < n - k)
                minSum += a[i];
            totalSum += a[i];
        }

        int i = 0, j = n - k - 1, curSum = minSum;
        while (j < n)
        {
            minSum = min(curSum, minSum);
            curSum -= a[i];
            i++, j++;
            if (j < n)
                curSum += a[j];
        }

        return totalSum - minSum;
    }
};

int main()
{

    return 0;
}