#include <bits/stdc++.h>
using namespace std;

int numberOfArithmeticSlices(vector<int> &a)
{
    int n = a.size();
    if (n < 3)
        return 0;
    vector<int> dp(n, 0);
    int ans = 0;

    for (int i = 2; i < n; i++)
    {
        if (a[i] - a[i - 1] == a[i - 1] - a[i - 2])
        {
            dp[i] = dp[i - 1] + 1;
        }
        ans += dp[i];
    }
    return ans;
}

int main()
{

    return 0;
}