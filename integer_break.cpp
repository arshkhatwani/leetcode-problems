#include <bits/stdc++.h>
using namespace std;

// Memoisation
// int solve(int n, int x, vector<int> &dp)
// {
//     if (n == 1)
//         return 1;
//     if (n <= 3)
//     {
//         if (x == n)
//             return n - 1;
//         return n;
//     }

//     if (dp[n] != -1)
//     {
//         return max(n, dp[n]);
//     }

//     int ans = 1;
//     for (int i = 1; i < n; i++)
//     {
//         ans = max(ans, i * solve(n - i, x, dp));
//     }
//     if (n != x)
//         ans = max(ans, n);

//     return dp[n] = ans;
// }

// int integerBreak(int n)
// {
//     vector<int> dp(n + 1, -1);
//     return solve(n, n, dp);
// }

// Tabulation
int integerBreak(int n)
{
    if (n <= 3)
        return n - 1;
    vector<int> dp(n + 1, 0);
    // dp[0] = 1;   // not neccessary to write
    // dp[1] = 1;   // not neccessary to write
    dp[2] = 1;
    dp[3] = 2;

    for (int i = 4; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            int ans = max(j * dp[i - j], j * (i - j));
            dp[i] = max(dp[i], ans);
        }
        if (i != n)
            dp[i] = max(dp[i], i);
    }

    return dp[n];
}

int main()
{

    return 0;
}