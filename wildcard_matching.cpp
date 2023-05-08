#include <bits/stdc++.h>
using namespace std;

// Tabulation + Space optimised
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.length(), n = p.length();
        vector<int> cur(n + 1, 0), next(n + 1, 0);

        for (int i = m; i >= 0; i--)
        {
            next = cur;
            cur = vector<int>(n + 1, 0);
            for (int j = n; j >= 0; j--)
            {
                if (i == m and j == n)
                    cur[j] = true;
                else if (i == m and j < n and p[j] == '*')
                    cur[j] = cur[j + 1];
                else if (i == m or j == n)
                    cur[j] = false;
                else if (s[i] == p[j] or p[j] == '?')
                    cur[j] = next[j + 1];
                else if (p[j] == '*')
                    cur[j] = next[j] or next[j + 1] or cur[j + 1];
                else
                    cur[j] = false;
            }
        }

        return cur[0];
    }
};

// Tabulation
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.length(), n = p.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        for (int i = m; i >= 0; i--)
        {
            for (int j = n; j >= 0; j--)
            {
                if (i == m and j == n)
                    dp[i][j] = true;
                else if (i == m and j < n and p[j] == '*')
                    dp[i][j] = dp[i][j + 1];
                else if (i == m or j == n)
                    dp[i][j] = false;
                else if (s[i] == p[j] or p[j] == '?')
                    dp[i][j] = dp[i + 1][j + 1];
                else if (p[j] == '*')
                    dp[i][j] = dp[i + 1][j] or dp[i + 1][j + 1] or dp[i][j + 1];
                else
                    dp[i][j] = false;
            }
        }

        return dp[0][0];
    }
};

// Memoisation
class Solution
{
    bool f(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {
        int m = s.length(), n = p.length();

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i == m and j == n)
            return true;
        if (i == m and j < n and p[j] == '*')
            return dp[i][j] = f(s, p, i, j + 1, dp);
        if (i == m or j == n)
            return false;

        if (s[i] == p[j] or p[j] == '?')
            return dp[i][j] = f(s, p, i + 1, j + 1, dp);

        if (p[j] == '*')
            return dp[i][j] = f(s, p, i + 1, j, dp) or f(s, p, i + 1, j + 1, dp) or f(s, p, i, j + 1, dp);

        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p)
    {
        int m = s.length(), n = p.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return f(s, p, 0, 0, dp);
    }
};

int main()
{

    return 0;
}