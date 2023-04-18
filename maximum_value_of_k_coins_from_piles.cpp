#include <bits/stdc++.h>
using namespace std;

// HINT: For each pile i, what will be the total value of coins we can collect if we choose the first j coins?

// Tabulation
class Solution
{
public:
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        int n = piles.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int t = 1; t <= k; t++)
            {
                int ans = 0, sum = 0;
                for (int j = 0; j <= t && j <= piles[i].size(); j++)
                {
                    int subAns = sum + dp[i + 1][t - j];
                    ans = max(ans, subAns);
                    if (j < piles[i].size())
                        sum += piles[i][j];
                }
                dp[i][t] = ans;
            }
        }

        return dp[0][k];
    }
};

// Memoisation
class Solution
{
    vector<vector<int>> dp;
    int solve(vector<vector<int>> &piles, int i, int k)
    {
        int n = piles.size();
        if (i == n or k == 0)
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        int ans = 0, sum = 0;
        for (int j = 0; j <= k && j <= piles[i].size(); j++)
        {
            int subAns = sum + solve(piles, i + 1, k - j);
            ans = max(ans, subAns);
            if (j < piles[i].size())
                sum += piles[i][j];
        }

        return dp[i][k] = ans;
    }

public:
    int maxValueOfCoins(vector<vector<int>> &piles, int k)
    {
        int n = piles.size();
        dp = vector<vector<int>>(n, vector<int>(k + 1, -1));
        return solve(piles, 0, k);
    }
};

int main()
{

    return 0;
}