#include <bits/stdc++.h>
using namespace std;

int longestArithSeqLength(vector<int> &a)
{
    int n = a.size();
    vector<unordered_map<int, int>> dp(n);
    int ans = 2;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = a[i] - a[j];
            if (dp[j].find(diff) != dp[j].end())
            {
                dp[i][diff] = dp[j][diff] + 1;
            }
            else
            {
                dp[i][diff] = 2;
            }
            ans = max(dp[i][diff], ans);
        }
    }

    return ans;
}

int main()
{

    return 0;
}