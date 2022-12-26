#include <bits/stdc++.h>
using namespace std;

/*
The problem is similar to TSP

We can first take the sum of array and divide it by k, if the sum is divisible by k. Then there is a possibility to divide the array into k equal sum subsets

-> Now the subset sum = total sum of array / k. So now we have to recursively pick elements and try to form the subset sum k times
-> Since the array length is [1,16] we can use a bitmask to keep track of picked elements
-> Every time we pick an element we recur for subset sum - picked element.
-> And when the subset sum gets 0 we recur for k - 1.
-> When k reaches 0, we know that the array can be divided into subsets with equal sums.
See the code to understand more

The above recursion can have overlapping subproblems, hence it can be memoised using 2D DP array with using 'mask' and 'k'
*/

class Solution
{
    vector<vector<int>> dp;

    int solve(vector<int> &a, int sum, int k, int mask, int reqSum)
    {
        if (k == 0)
            return 1;
        if (sum == 0)
            return solve(a, reqSum, k - 1, mask, reqSum);

        if (dp[k][mask] != -1)
            return dp[k][mask];

        for (int i = 0; i < a.size(); i++)
        {
            int isPicked = ((1 << i) & mask) > 0;
            if (!isPicked and sum >= a[i])
            {
                int newMask = (1 << i) | mask;
                int subAns = solve(a, sum - a[i], k, newMask, reqSum);
                if (subAns)
                    return 1;
            }
        }

        return dp[k][mask] = 0;
    }

public:
    bool canPartitionKSubsets(vector<int> &a, int k)
    {
        int n = a.size(), reqSum = 0;
        dp = vector<vector<int>>(k + 1, vector<int>(1 << n, -1));

        for (auto i : a)
            reqSum += i;
        if (reqSum % k)
            return 0;
        reqSum /= k;

        return solve(a, reqSum, k, 0, reqSum);
    }
};

int main()
{

    return 0;
}