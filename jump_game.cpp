#include <bits/stdc++.h>
using namespace std;

// Greedy
class Solution
{
public:
    bool canJump(vector<int> &a)
    {
        int n = a.size(), maxReach = 0;

        for (int i = 0; i < n && maxReach != n - 1; i++)
        {
            if (i <= maxReach)
                maxReach = max(maxReach, a[i] + i);
            else
                return false;
        }

        return true;
    }
};

// DP
class Solution
{
public:
    bool solve(vector<int> &a, int n, int i, vector<int> &dp)
    {
        if (i == n)
        {
            return true;
        }
        if (i > n)
            return false;
        if (a[i] == 0)
            return false;
        if (dp[i] != -1)
            return false;

        dp[i] = 1;
        bool ans = false;
        for (int j = 1; j <= a[i]; j++)
        {
            ans = ans or solve(a, n, i + j, dp);
            if (ans)
                return true;
        }
        return ans;
    }
    bool canJump(vector<int> &a)
    {
        int n = a.size();
        vector<int> dp(n, -1);
        return solve(a, n - 1, 0, dp);
    }
};

int main()
{

    return 0;
}