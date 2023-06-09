#include <bits/stdc++.h>
using namespace std;

// Video: https://youtu.be/d-B_gk_gJtQ

// Greedy
class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int n = costs.size();

        vector<pair<int, int>> a;
        for (int i = 0; i < n; i++)
        {
            int diff = costs[i][0] - costs[i][1];
            a.push_back({diff, i});
        }
        sort(a.begin(), a.end());

        int cost1 = 0;
        for (int i = 0; i < n; i++)
        {
            int idx = a[i].second;
            if (i <= n / 2 - 1)
            {
                cost1 += costs[idx][0];
            }
            else
            {
                cost1 += costs[idx][1];
            }
        }

        return cost1;
    }
};

// DP
class Solution
{
    vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(51, vector<vector<int>>(51, vector<int>(101, -1)));
    int solve(int n1, int n2, int n, vector<vector<int>> &costs)
    {
        if (n == 0)
            return 0;

        if (dp[n1][n2][n] != -1)
            return dp[n1][n2][n];

        int choice1 = n1 > 0 ? costs[n - 1][0] + solve(n1 - 1, n2, n - 1, costs) : costs[n - 1][1] + solve(n1, n2 - 1, n - 1, costs);
        int choice2 = n2 > 0 ? costs[n - 1][1] + solve(n1, n2 - 1, n - 1, costs) : costs[n - 1][0] + solve(n1 - 1, n2, n - 1, costs);

        return dp[n1][n2][n] = min(choice1, choice2);
    }

public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int n = costs.size();

        return solve(n / 2, n / 2, n, costs);
    }
};

int main()
{

    return 0;
}