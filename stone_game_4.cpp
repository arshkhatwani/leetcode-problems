#include <bits/stdc++.h>
using namespace std;

bool winnerSquareGame(int n)
{
    vector<bool> dp(n + 1, 0);

    dp[0] = false;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j * j <= i; j++)
        {
            dp[i] = dp[i] or !dp[i - j * j];
            if (dp[i] == true)
                break; // once any dp[i] comes true we know that it is a win for that 'i' as players are playing optimally, so we break the inside loop there
        }
    }

    return dp[n];
}

int main()
{

    return 0;
}