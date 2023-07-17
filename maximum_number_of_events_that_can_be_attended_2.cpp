#include <bits/stdc++.h>
using namespace std;

// Bottom Up DP
class Solution
{
public:
    int maxValue(vector<vector<int>> &events, int k)
    {
        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        vector<int> starts;

        sort(events.begin(), events.end());
        for (int i = 0; i < n; i++)
        {
            starts.push_back(events[i][0]);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int _k = 1; _k <= k; _k++)
            {
                int idx = lower_bound(starts.begin(), starts.end(), events[i][1] + 1) - starts.begin();
                int choose = events[i][2] + dp[idx][_k - 1];
                int notChoose = dp[i + 1][_k];
                dp[i][_k] = max(choose, notChoose);
            }
        }

        return dp[0][k];
    }
};

// Top Down DP
class Solution
{
    int solve(int i, int k, vector<vector<int>> &events, vector<int> &starts, vector<vector<int>> &dp)
    {
        int n = events.size();
        if (i == n)
            return 0;
        if (k == 0)
            return 0;

        if (dp[i][k] != -1)
            return dp[i][k];

        int idx = lower_bound(starts.begin(), starts.end(), events[i][1] + 1) - starts.begin();
        int choose = events[i][2] + solve(idx, k - 1, events, starts, dp);
        int notChoose = solve(i + 1, k, events, starts, dp);

        return dp[i][k] = max(choose, notChoose);
    }

public:
    int maxValue(vector<vector<int>> &events, int k)
    {
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        vector<int> starts;

        sort(events.begin(), events.end());
        for (int i = 0; i < n; i++)
        {
            starts.push_back(events[i][0]);
        }

        return solve(0, k, events, starts, dp);
    }
};

int main()
{

    return 0;
}