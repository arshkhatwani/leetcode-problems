#include <bits/stdc++.h>
using namespace std;

/*
In this problem we cannot solve it like the way we solved the cost to cut a chocolate problem, because if we burst balloon in the subproblems cannot be solved as they would be depend on it

So, in this question we decide to work from bottom up and we pick balloons we will burst at last
so the in the range (l, r) for i'th balloon where the coins would be a[i]*a[l-1]*a[r+1] and then we will add the result of subproblems: (l, i-1) and (i+1, r)

and we will push one balloon of value 1 in start and end of the given array to avoid complications

Watch video to understand more: https://youtu.be/Yz4LlDSlkns
*/

class Solution
{
    vector<vector<int>> dp;

    int f(int l, int r, vector<int> &a)
    {
        if (l > r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0, subAns = 0, coins;

        for (int i = l; i <= r; i++)
        {
            coins = a[i] * a[l - 1] * a[r + 1];
            subAns = coins + f(l, i - 1, a) + f(i + 1, r, a);
            ans = max(ans, subAns);
        }

        return dp[l][r] = ans;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));

        return f(1, n - 2, nums);
    }
};

// Tabulation
class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));
        int ans = 0, subAns = 0, coins;

        for (int l = n - 2; l >= 1; l--)
        {
            for (int r = 1; r <= n - 2; r++)
            {
                if (l > r)
                    continue;

                ans = 0, subAns = 0;

                for (int i = l; i <= r; i++)
                {
                    coins = nums[i] * nums[l - 1] * nums[r + 1];
                    subAns = coins + dp[l][i - 1] + dp[i + 1][r];
                    ans = max(ans, subAns);
                }

                dp[l][r] = ans;
            }
        }

        return dp[1][n - 2];
    }
};

int main()
{

    return 0;
}