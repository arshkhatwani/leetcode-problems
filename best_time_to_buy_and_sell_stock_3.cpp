#include <bits/stdc++.h>
using namespace std;

// This is same as Buy and Sell stock 2 problem with a little twist
// Below is the memoised recursion
class Solution
{
private:
    vector<vector<vector<int>>> dp;

    int solve(vector<int> &prices, int i, bool canBuy, int transactions)
    {
        if (i == prices.size() or transactions == 2)
        {
            return 0;
        }

        if (dp[i][transactions][canBuy] != -1)
            return dp[i][transactions][canBuy];

        int choice1 = 0, choice2 = 0;
        if (canBuy)
        {
            choice1 = -prices[i] + solve(prices, i + 1, false, transactions);
        }
        else
        {
            choice1 = prices[i] + solve(prices, i + 1, true, transactions + 1);
        }

        choice2 = solve(prices, i + 1, canBuy, transactions);

        return dp[i][transactions][canBuy] = max(choice1, choice2);
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(3, vector<int>(2, -1)));
        return solve(prices, 0, true, 0);
    }
};

// Below is the tabulation with commented code to see normal and space optimised tabulation
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();

        // vector <vector <vector <int>>> dp = vector<vector <vector<int>>> (n+1, vector <vector <int>> (3, vector <int> (2, 0)));
        vector<vector<int>> dp(3, vector<int>(2, 0));

        int choice1 = 0, choice2 = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            for (int cap = 0; cap < 2; cap++)
            {
                for (int canBuy = 0; canBuy < 2; canBuy++)
                {

                    if (canBuy)
                    {
                        // choice1 = -prices[i] + dp[i+1][cap][0];
                        choice1 = -prices[i] + dp[cap][0];
                    }
                    else
                    {
                        // choice1 = prices[i] + dp[i+1][cap+1][1];
                        choice1 = prices[i] + dp[cap + 1][1];
                    }

                    // choice2 = dp[i+1][cap][canBuy];
                    // dp[i][cap][canBuy] = max(choice1, choice2);

                    choice2 = dp[cap][canBuy];
                    dp[cap][canBuy] = max(choice1, choice2);
                }
            }
        }

        return dp[0][1];
    }
};

int main()
{

    return 0;
}