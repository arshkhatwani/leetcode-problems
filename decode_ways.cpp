#include <bits/stdc++.h>
using namespace std;

int numDecodings(string s)
{
    if (s[0] == '0')
        return 0;

    int n = s.length();
    vector<int> dp(n, 0);
    dp[0] = 1;

    for (int i = 1; i < n; i++)
    {
        int x = stoi(s.substr(i - 1, 2));

        if (s[i] != '0')
            dp[i] += dp[i - 1];

        if (x <= 26 and s[i - 1] != '0')
        {
            if (i > 1)
                dp[i] += dp[i - 2];
            else
                dp[i] += 1;
        }
        else if (x > 26 and s[i] == '0')
            dp[i] = 0;
    }

    return dp[n - 1];
}

int main()
{

    return 0;
}