#include <bits/stdc++.h>
using namespace std;

/*
This question is same as 0 1 knapsack
Read to understand in detail: https://leetcode.com/problems/ones-and-zeroes/discuss/95807/0-1-knapsack-detailed-explanation.
*/

// Tabulation with space optimisation
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int size = strs.size();
        // vector<vector <vector <int>>> dp(m+1, vector <vector<int>> (n+1, vector <int> (size+1, 0)));

        vector<vector<int>> prev(m + 1, vector<int>(n + 1, 0)), cur(m + 1, vector<int>(n + 1, 0));

        for (int idx = 1; idx <= size; idx++)
        {
            for (int i = 0; i <= m; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    int count0s = 0, count1s = 0;

                    for (int k = 0; k < strs[idx - 1].length(); k++)
                    {
                        if (strs[idx - 1][k] == '0')
                            count0s++;
                        else
                            count1s++;
                    }

                    // int notPick = dp[i][j][idx-1];
                    int notPick = prev[i][j];
                    int pick = 0;

                    if (i >= count0s and j >= count1s)
                    {
                        // pick = 1 + dp[i-count0s][j-count1s][idx-1];
                        pick = 1 + prev[i - count0s][j - count1s];
                    }

                    // dp[i][j][idx] = max(pick, notPick);
                    cur[i][j] = max(pick, notPick);
                }
            }
            prev = cur;
        }

        return cur[m][n];
    }
};

// Tabulation
class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int size = strs.size();
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(size + 1, 0)));

        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int idx = 1; idx <= size; idx++)
                {
                    int count0s = 0, count1s = 0;

                    for (int k = 0; k < strs[idx - 1].length(); k++)
                    {
                        if (strs[idx - 1][k] == '0')
                            count0s++;
                        else
                            count1s++;
                    }

                    int notPick = dp[i][j][idx - 1];
                    int pick = 0;

                    if (i >= count0s and j >= count1s)
                    {
                        pick = 1 + dp[i - count0s][j - count1s][idx - 1];
                    }

                    dp[i][j][idx] = max(pick, notPick);
                }
            }
        }

        return dp[m][n][size];
    }
};

// Memoisation
class Solution
{
    vector<vector<vector<int>>> dp;
    int f(int m, int n, int idx, vector<string> &strs)
    {
        if (idx == 0)
            return 0;

        if (dp[m][n][idx] != -1)
            return dp[m][n][idx];

        int count0s = 0, count1s = 0;
        for (int i = 0; i < strs[idx - 1].length(); i++)
        {
            if (strs[idx - 1][i] == '0')
                count0s++;
            else
                count1s++;
        }

        int pick = 0;

        if (m >= count0s and n >= count1s)
            pick = 1 + f(m - count0s, n - count1s, idx - 1, strs);

        int notPick = f(m, n, idx - 1, strs);

        return dp[m][n][idx] = max(pick, notPick);
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        int size = strs.size();
        dp = vector<vector<vector<int>>>(m + 1, vector<vector<int>>(n + 1, vector<int>(size + 1, -1)));

        return f(m, n, size, strs);
    }
};

int main()
{

    return 0;
}