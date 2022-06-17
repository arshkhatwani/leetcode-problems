#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &a, int i, int n, vector<int> &dp)
{
    if (n < i)
    {
        return 0;
    }
    if (n == i)
    {
        return a[i];
    }
    if (dp[n] != -1)
        return dp[n];

    int choice1 = a[n] + solve(a, i, n - 2, dp);
    int choice2 = solve(a, i, n - 1, dp);

    return dp[n] = max(choice1, choice2);
}
int rob(vector<int> &a)
{
    if (a.size() == 1)
        return a[0];
    vector<int> dp(a.size(), -1);
    int choice1 = solve(a, 1, a.size() - 1, dp);
    dp = vector<int>(a.size(), -1);
    int choice2 = solve(a, 0, a.size() - 2, dp);
    return max(choice1, choice2);
}

int main()
{

    return 0;
}