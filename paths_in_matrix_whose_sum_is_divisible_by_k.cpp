#include <bits/stdc++.h>
using namespace std;

/*
This problem can be solved using DP
See the code to understand
*/

// Memoisation
class Solution
{
    int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int f(vector<vector<int>> &a, int k, int m, int n, int sum)
    {
        if (m < 0 or n < 0)
            return 0;

        if (m == 0 and n == 0)
        {
            sum = (sum + a[m][n]) % k;
            if (sum == 0)
                return 1;
            return 0;
        }

        if (dp[m][n][sum] != -1)
            return dp[m][n][sum];

        int newSum = (sum + a[m][n]) % k;

        int up = f(a, k, m - 1, n, newSum) % MOD;
        int left = f(a, k, m, n - 1, newSum) % MOD;

        return dp[m][n][sum] = (up + left) % MOD;
    }

public:
    int numberOfPaths(vector<vector<int>> &a, int k)
    {
        int m = a.size(), n = a[0].size();

        dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(k, -1)));

        return f(a, k, m - 1, n - 1, 0);
    }
};

// Tabulation
class Solution
{
    int MOD = 1e9 + 7;

public:
    int numberOfPaths(vector<vector<int>> &a, int k)
    {
        int m = a.size(), n = a[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k, 0)));

        dp[0][0][a[0][0] % k] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                for (int sum = 0; sum < k; sum++)
                {
                    int newSum = (sum + a[i][j]) % k;

                    int up = i > 0 ? dp[i - 1][j][sum] : 0;
                    int left = j > 0 ? dp[i][j - 1][sum] : 0;

                    dp[i][j][newSum] += up + left;
                    dp[i][j][newSum] %= MOD;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};

int main()
{

    return 0;
}