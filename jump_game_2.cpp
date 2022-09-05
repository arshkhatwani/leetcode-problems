#include <bits/stdc++.h>
using namespace std;

// Logic https://youtu.be/phgjL7SbsWs

/*
Greedy Approach

We keep a track of farthest index which we can reach and we also keep a current variable which helps us in determining when the current jump has exhausted and we can increase our jumps

Watch video for detailed explanation: https://youtu.be/wLPdkLM_BWo
*/

// Greedy Solution O(n)
class Solution
{
public:
    int jump(vector<int> &a)
    {
        int n = a.size();
        int jumps = 0, farthest = 0, current = 0;

        for (int i = 0; i < n - 1; i++)
        {
            farthest = max(farthest, i + a[i]);

            if (i == current)
            {
                current = farthest;
                jumps++;
            }
        }

        return jumps;
    }
};

// DP Solution
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