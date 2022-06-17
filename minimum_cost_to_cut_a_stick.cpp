#include <bits/stdc++.h>
using namespace std;

/*
The logic is same as cost to cut a chocolate probelm except we are here memoising according to range in indices of the array rather than the cuts since cuts[i] has huge constraints

So watch video to understand more: https://youtu.be/xwomavsC86c
*/

class Solution
{
    vector<vector<int>> dp;

    int f(vector<int> &a, int l, int r)
    {
        if (l > r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = INT_MAX, subAns = INT_MAX, size = a[r + 1] - a[l - 1];

        for (int i = l; i <= r; i++)
        {
            subAns = size + f(a, l, i - 1) + f(a, i + 1, r);
            ans = min(ans, subAns);
        }

        return dp[l][r] = ans;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int size = cuts.size();
        dp = vector<vector<int>>(102, vector<int>(102, -1));

        return f(cuts, 1, size - 2);
    }
};

class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int size = cuts.size();

        vector<vector<int>> dp(102, vector<int>(102, 0));

        for (int l = size - 2; l >= 1; l--)
        {
            for (int r = 1; r <= size - 2; r++)
            {
                if (l > r)
                    continue;

                int ans = INT_MAX, subAns = INT_MAX, size = cuts[r + 1] - cuts[l - 1];

                for (int i = l; i <= r; i++)
                {
                    subAns = size + dp[l][i - 1] + dp[i + 1][r];
                    ans = min(ans, subAns);
                }

                dp[l][r] = ans;
            }
        }

        return dp[1][size - 2];
    }
};

int main()
{

    return 0;
}