#include <bits/stdc++.h>
using namespace std;

// This problem is similar to longest common subsequence

// Top down DP
class Solution
{
    int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp)
    {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int choice1 = s[i] == t[j] ? solve(s, t, i - 1, j - 1, dp) : 0;
        int choice2 = solve(s, t, i - 1, j, dp);

        return dp[i][j] = choice1 + choice2;
    }

public:
    int numDistinct(string s, string t)
    {
        int m = s.length(), n = t.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(s, t, m - 1, n - 1, dp);
    }
};

// Bottom up DP
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.length(), n = t.length();
        int MOD = 1e9 + 7;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= m; i++)
            {
                int choice1 = s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0;
                int choice2 = dp[i - 1][j];
                dp[i][j] = choice1 + choice2;
                dp[i][j] %= MOD;
            }
        }

        return dp[m][n];
    }
};

// Bottom up DP, space optimised
class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.length(), n = t.length();
        int MOD = 1e9 + 7;
        vector<int> prev(n + 1, 0), cur(n + 1, 0);

        prev[0] = 1;
        for (int i = 1; i <= m; i++)
        {
            cur = vector<int>(n + 1, 0);
            cur[0] = 1;
            for (int j = 1; j <= n; j++)
            {
                int choice1 = s[i - 1] == t[j - 1] ? prev[j - 1] : 0;
                int choice2 = prev[j];
                cur[j] = choice1 + choice2;
                cur[j] %= MOD;
            }
            prev = cur;
        }

        return cur[n];
    }
};

int main()
{

    return 0;
}