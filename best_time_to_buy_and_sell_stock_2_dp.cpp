#include <bits/stdc++.h>
using namespace std;

// watch if you dont understand the below logic https://youtu.be/nGJmxkUJQGs

/*
We can either have an open position(holding stock) or we cannot have holding
If we have no holding position, i.e we can buy a stock
    Then we have 2 choices for every day
        To buy the stock on that day
        To not buy the stock on that day
If we have holding position open, i.e we already have a stock so we need to sell it
    Then we have 2 choices for every day
        To sell the stock on that day
        To not sell the stock on that day

T.C of plain recursion would be 2^n
If we draw the recursion flowchart we can see overlapping subproblems
So we can memoise it using 2d array of size (n x 2), n for array length, 2 for holding status
*/

// Below is the recursive memoised solution
/*
Iss niche wale solution se pehle apan profit variable bana ke recursion mai bhejre the jo ki plain recursion mai toh right ans dera the magar memoised wale mai nahi, this is because kyuki profit add hone ke kaaran jo overlapping subproblems the wo apne aap unique bnn jare the kyuki har overlapping different ans return krra tha, toh memoise pe WA aara tha toh apan profit seedha add krre hai and recursion function mai as a parameter nahi bhejre hai niche wale solution mai

Iske niche ek commented solution hai usse dekh ke upar jo galti mention ki hai wo samaj aajayegi
*/

class Solution
{
private:
    vector<vector<int>> dp;

    int solve(vector<int> &prices, int i, bool status)
    {
        if (i == prices.size())
        {
            return 0;
        }

        if (dp[i][status] != -1)
            return dp[i][status];

        int choice1 = 0, choice2 = 0;

        if (status)
        {                                                      // cannot buy
            choice1 = prices[i] + solve(prices, i + 1, false); // sold
            choice2 = solve(prices, i + 1, status);            // did not sell
        }

        else
        {                                                      // can buy
            choice1 = -prices[i] + solve(prices, i + 1, true); // bought
            choice2 = solve(prices, i + 1, status);            // did not buy
        }

        return dp[i][status] = max(choice1, choice2);
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        dp = vector<vector<int>>(n, vector<int>(2, -1));

        return solve(prices, 0, false);
    }
};

// Below is the mistake mentioned above
/*
class Solution {
private:
    vector <vector <int>> dp;

    int solve(vector <int> &prices, int i, int profit, bool status){
        if(i == prices.size()){
            return profit;
        }

        if(dp[i][status] != -1) return dp[i][status];

        int choice1 = 0, choice2 = 0;

        if(status){ // cannot buy
            choice1 = solve(prices, i+1, profit + prices[i], false); // sold
            choice2 = solve(prices, i+1, profit, status); // did not sell
        }

        else{ // can buy
            choice1 = solve(prices, i+1, profit - prices[i], true); // bought
            choice2 = solve(prices, i+1, profit, status); // did not buy
        }

        return dp[i][status] = max(choice1, choice2);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp = vector<vector <int>> (n, vector <int> (2, -1));

        return solve(prices, 0, 0, false);
    }
};
*/

// Below is the tabulation with commented code to see normal and space optimised tabulation
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size(), choice1 = 0, choice2 = 0;
        // vector <vector <int>> dp(n+1, vector <int> (2, 0));
        vector<int> dp(2, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            for (int status = 0; status <= 1; status++)
            {
                if (status)
                {
                    // choice1 = prices[i] + dp[i+1][0];
                    choice1 = prices[i] + dp[0];
                }
                else
                {
                    // choice1 = -prices[i] + dp[i+1][1];
                    choice1 = -prices[i] + dp[1];
                }
                // choice2 = dp[i+1][status];
                // dp[i][status] = max(choice1, choice2);

                choice2 = dp[status];
                dp[status] = max(choice1, choice2);
            }
        }

        // return dp[0][0];
        return dp[0];
    }
};

int main()
{

    return 0;
}