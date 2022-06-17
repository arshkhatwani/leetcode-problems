#include <bits/stdc++.h>
using namespace std;

/*
This question is not present in leetcode, I just had to save it somewhere so I saved it here

The logic is same as longest common subsequence except we don't put that
dp[i][j] = max(dp[i-1][j], dp[i][j-1]) condition here

Rest all is same

Watch video to understand in detail https://youtu.be/_wP9mWNPL5w
*/

int lcs(string &s1, string &s2)
{
    int m = s1.length(), n = s2.length(), ans = 0;

    // 	vector <vector <int>> dp(m+1, vector <int> (n + 1, 0));

    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                // 				dp[i][j] = 1 + dp[i-1][j-1];
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = 0;
            }
            // 			ans = max(ans, dp[i][j]);
            ans = max(ans, curr[j]);
        }
        prev = curr;
    }

    return ans;
}

int main()
{

    return 0;
}