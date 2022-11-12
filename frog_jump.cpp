#include <bits/stdc++.h>
using namespace std;

/*
Recursive approach
If we are standing at some index 'idx' and we know our last jump

Since the array is sorted we can binary search the value obtained after adding a[i] + lastjump, a[i] + lastjump + 1, a[i] + lastjump - 1

If the value is present then we call the recusrive function for the new index and send the value of new jump

If we reach index = size - 1, we return true

DP memoisation
Since the above approach has overlapping subproblems it can be memoised using 2D array
So the above recursion can be optimised using index and lastjump value
*/

class Solution
{
    vector<int> jumps = {-1, 0, 1};
    vector<vector<int>> dp;
    int binarySearch(vector<int> &a, int key)
    {
        int low = 0, high = a.size() - 1, mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (a[mid] == key)
                return mid;
            else if (a[mid] > key)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
    bool solve(vector<int> &stones, int idx, int lastJump)
    {
        int n = stones.size();
        if (idx == n - 1)
        {
            return true;
        }
        if (lastJump == 0)
            return false;

        if (dp[idx][lastJump] != -1)
            return dp[idx][lastJump];

        int ans = false;

        for (auto i : jumps)
        {
            int newIdx = binarySearch(stones, stones[idx] + lastJump + i);
            if (newIdx != -1)
            {
                ans = ans or solve(stones, newIdx, lastJump + i);
            }
        }

        return dp[idx][lastJump] = ans;
    }

public:
    bool canCross(vector<int> &stones)
    {
        int n = stones.size();
        if (n > 1 and stones[1] != 1)
            return false;

        dp = vector<vector<int>>(n, vector<int>(n, -1));

        return solve(stones, 1, 1);
    }
};

int main()
{

    return 0;
}