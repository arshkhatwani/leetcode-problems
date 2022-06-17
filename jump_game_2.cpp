#include <bits/stdc++.h>
using namespace std;

// Logic https://youtu.be/phgjL7SbsWs

int jump(vector<int> &a)
{
    int n = a.size();
    vector<int> dp(n, 1e9);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= a[i]; j++)
        {
            if (i + j < n)
                dp[i] = min(dp[i], dp[i + j] + 1);
        }
    }
    return dp[0];
}

int main()
{

    return 0;
}