#include <bits/stdc++.h>
using namespace std;

// This problem can be solved using DP

// Tabulation
class Solution
{
    vector<int> daysAdd{1, 7, 30};

public:
    int mincostTickets(vector<int> &a, vector<int> &costs)
    {
        int n = a.size();
        vector<int> dp(n + 1, 0);

        for (int curIdx = n - 1; curIdx >= 0; curIdx--)
        {
            int ans = INT_MAX;
            for (int i = 0; i < 3; i++)
            {
                int cost = costs[i];
                int day = daysAdd[i];
                int newIdx = upper_bound(a.begin(), a.end(), day + a[curIdx] - 1) - a.begin();
                int subAns = cost + dp[newIdx];

                ans = min(subAns, ans);
            }
            dp[curIdx] = ans;
        }

        return dp[0];
    }
};

// Memoisation
class Solution
{
    vector<int> daysAdd{1, 7, 30};
    vector<int> dp;
    int f(int curIdx, vector<int> &a, vector<int> &costs)
    {
        int n = a.size();
        if (curIdx == n)
            return 0;

        if (dp[curIdx] != -1)
            return dp[curIdx];

        int ans = INT_MAX;
        for (int i = 0; i < 3; i++)
        {
            int cost = costs[i];
            int day = daysAdd[i];
            int newIdx = upper_bound(a.begin(), a.end(), day + a[curIdx] - 1) - a.begin();
            int subAns = cost + f(newIdx, a, costs);

            ans = min(subAns, ans);
        }

        return dp[curIdx] = ans;
    }

public:
    int mincostTickets(vector<int> &a, vector<int> &costs)
    {
        int n = a.size();
        dp.resize(n, -1);
        return f(0, a, costs);
    }
};

int main()
{

    return 0;
}