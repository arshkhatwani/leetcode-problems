#include <bits/stdc++.h>
using namespace std;

// This question is similar to 0-1 Knapsack problem, checkout LeetCode editorial and code to understand more

// Tabulation
class Solution
{
    int MOD = 1e9 + 7;

public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        vector<vector<vector<int>>> dp(101, vector<vector<int>>(101, vector<int>(101, 0)));

        int totalSize = group.size();
        for (int i = totalSize; i >= 0; i--)
        {
            for (int m = 0; m <= n; m++)
            {
                if (i == totalSize or m == 0)
                {
                    dp[i][minProfit][m] = 1;
                    continue;
                }
                for (int totalProfit = minProfit; totalProfit >= 0; totalProfit--)
                {
                    int newProfit = min(minProfit, totalProfit + profit[i]);
                    int pick = m - group[i] >= 0 ? dp[i + 1][newProfit][m - group[i]] : 0;
                    int notPick = dp[i + 1][totalProfit][m];

                    long long total = pick + notPick;
                    dp[i][totalProfit][m] = total % MOD;
                }
            }
        }

        return dp[0][0][n];
    }
};

// Memoisation
class Solution
{
    int MOD = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int f(int n, int totalProfit, int i, int &minProfit, vector<int> &group, vector<int> &profit)
    {
        int m = group.size();
        if (n < 0)
            return 0;
        if (n == 0 or i == m)
        {
            if (totalProfit >= minProfit)
                return 1;
            else
                return 0;
        }

        if (dp[n][i][totalProfit] != -1)
            return dp[n][i][totalProfit];

        int pick = f(n - group[i], min(minProfit, totalProfit + profit[i]), i + 1, minProfit, group, profit);
        int notPick = f(n, totalProfit, i + 1, minProfit, group, profit);

        long long total = pick + notPick;

        return dp[n][i][totalProfit] = total % MOD;
    }

public:
    int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
    {
        dp = vector<vector<vector<int>>>(101, vector<vector<int>>(101, vector<int>(101, -1)));
        return f(n, 0, 0, minProfit, group, profit) % MOD;
    }
};

int main()
{

    return 0;
}