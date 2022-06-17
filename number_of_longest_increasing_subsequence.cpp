#include <bits/stdc++.h>
using namespace std;

// logic article https://www.geeksforgeeks.org/number-of-longest-increasing-subsequences/

int findNumberOfLIS(vector<int> &a)
{
    int n = a.size(), ans = 0, total = 0;
    vector<int> dp(n, 0);
    vector<int> count(n, 1);

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                if (dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                }
                else if (dp[i] == dp[j] + 1)
                {
                    count[i] += count[j];
                }
            }
        }
        ans = max(dp[i], ans);
    }
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == ans)
            total += count[i];
    }
    return total;
}

int main()
{

    return 0;
}