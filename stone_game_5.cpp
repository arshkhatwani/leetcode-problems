#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> prefix;
    vector<vector<int>> dp;

    void makePrefix(vector<int> &a)
    {
        int n = a.size();
        prefix = vector<int>(n, 0);
        prefix[0] = a[0];

        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + a[i];
        }
    }

public:
    int solve(vector<int> &a, int i, int j)
    {
        if (j - i == 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        int n = a.size(), ans = 0, score = 0, sum1, sum2;
        for (int p = i + 1; p <= j; p++)
        {
            sum1 = i > 0 ? prefix[p - 1] - prefix[i - 1] : prefix[p - 1];
            sum2 = prefix[j] - prefix[p - 1];

            if (sum1 < sum2)
            {
                score = sum1 + solve(a, i, p - 1);
            }
            else if (sum1 > sum2)
            {
                score = sum2 + solve(a, p, j);
            }
            else
            {
                score = sum1 + max(solve(a, i, p - 1), solve(a, p, j));
            }

            ans = max(score, ans);
        }

        return dp[i][j] = ans;
    }
    int stoneGameV(vector<int> &a)
    {
        int n = a.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));

        makePrefix(a);

        int ans = solve(a, 0, n - 1);

        return ans;
    }
};

int main()
{

    return 0;
}