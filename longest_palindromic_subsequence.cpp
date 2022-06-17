#include <bits/stdc++.h>
using namespace std;

// We can say that Longest Common Subsequence of a string and its reverse can be considered as Longest Palindromic Subsequence

// Space optimised solution
int longestPalindromeSubseq(string s2)
{
    string s1 = s2;
    reverse(s2.begin(), s2.end());
    int n = s1.length();

    // vector <vector <int>> dp(n+1,vector <int> (n+1, 0));
    vector<int> prev(n + 1, 0), curr(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                // dp[i][j] = dp[i-1][j-1] + 1;
                curr[j] = prev[j - 1] + 1;
            }
            else
            {
                // dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        prev = curr;
    }

    return curr[n];
}

int main()
{

    return 0;
}