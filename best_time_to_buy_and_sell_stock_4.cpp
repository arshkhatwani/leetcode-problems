#include <bits/stdc++.h>
using namespace std;

// This question is same as buy and sell stock 3

// Memoised recursion
class Solution
{
private:
    vector<vector<vector<int>>> dp;
    int solve(vector<int> &prices, int i, int k, bool canBuy)
    {
        if (k == 0 or i == prices.size())
            return 0;

        if (dp[i][k][canBuy] != -1)
            return dp[i][k][canBuy];

        int choice1 = 0, choice2 = 0;
        if (canBuy)
        {
            choice1 = -prices[i] + solve(prices, i + 1, k, false);
        }
        else
        {
            choice1 = prices[i] + solve(prices, i + 1, k - 1, true);
        }
        choice2 = solve(prices, i + 1, k, canBuy);

        return dp[i][k][canBuy] = max(choice1, choice2);
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));

        return solve(prices, 0, k, true);
    }
};

// Below is the tabulation with commented code to see normal and space optimised tabulation
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        // vector <vector <vector <int>>> dp = vector <vector <vector <int>>>(n+1, vector <vector <int>> (k+1, vector <int> (2, 0)));
        vector<vector<int>> dp = vector<vector<int>>(k + 1, vector<int>(2, 0));

        int choice1 = 0, choice2 = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int cap = k; cap > 0; cap--)
            {
                for (int canBuy = 0; canBuy <= 1; canBuy++)
                {
                    if (canBuy)
                    {
                        // choice1 = -prices[i] + dp[i+1][cap][0];
                        choice1 = -prices[i] + dp[cap][0];
                    }
                    else
                    {
                        // choice1 = prices[i] + dp[i+1][cap-1][1];
                        choice1 = prices[i] + dp[cap - 1][1];
                    }
                    // choice2 = dp[i+1][cap][canBuy];
                    // dp[i][cap][canBuy] = max(choice1, choice2);

                    choice2 = dp[cap][canBuy];
                    dp[cap][canBuy] = max(choice1, choice2);
                }
            }
        }

        return dp[k][1];
    }
};

int main()
{

    return 0;
}