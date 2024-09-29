#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int superEggDrop(int k, int n)
    {
        if (n == 0 or n == 1)
            return n;
        if (k == 1)
            return n;

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= k; i++)
        {
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[1][i] = i;
        }

        for (int egg = 2; egg <= k; egg++)
        {
            for (int flr = 2; flr <= n; flr++)
            {
                int ans = 1e9, temp = 0;
                int low = 1, high = flr;

                while (low <= high)
                {
                    int mid = low + (high - low) / 2;
                    int eggBreak = dp[egg - 1][mid - 1]; // left
                    int notBreak = dp[egg][flr - mid];   // right

                    temp = 1 + max(eggBreak, notBreak);
                    ans = min(ans, temp);

                    if (eggBreak < notBreak)
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }

                dp[egg][flr] = ans;
            }
        }

        return dp[k][n];
    }
};

int main()
{

    return 0;
}