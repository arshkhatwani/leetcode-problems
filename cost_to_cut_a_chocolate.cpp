#include <bits/stdc++.h>
using namespace std;

// This problem is in CodeStudio

/*
Let's say we are in a range (l,r) and we are iterating the cuts array so we can say at every valid point i, we have 2 choices
Make a cut on that point
Not make a cut on that point
So we need to check all possible ways for this we will require recursion

So now, to check if making a cut is valid or not we just need to traverse the array and see that if the current element is within range (l,r) or not, if yes then it is a valid point to cut

So now if we make a cut at a certain point 'i' the array will be split into two parts (l,i) and (i, r) and these parts may have some points for cutting, so we call the function recursively for both of them

Since there will be overlapping subproblems, we can memoise it using 2d array and store the solutions for range (l,r) in dp[l][r]

So it would go something like this,

int ans = INT_MAX, size = r - l, subAns = INT_MAX;
for(auto i : a){
    if(i > l and i < r){ // to see if the cut is valid
        subAns = size + f(a, l, i, dp) + f(a, i, r, dp);
        ans = min(ans, subAns);
    }
}
if(ans == INT_MAX) ans = 0;
*/

// Recursion + Memoisation
int f(vector<int> &a, int l, int r, vector<vector<int>> &dp)
{
    int ans = INT_MAX, size = r - l, subAns = INT_MAX;

    if (dp[l][r] != -1)
        return dp[l][r];

    for (auto i : a)
    {
        if (i > l and i < r)
        {
            subAns = size + f(a, l, i, dp) + f(a, i, r, dp);
            ans = min(ans, subAns);
        }
    }

    if (ans == INT_MAX)
        return 0;

    return dp[l][r] = ans;
}

int cost(int n, int c, vector<int> &cuts)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

    return f(cuts, 0, n, dp);
}

// Tabulation
int cost(int n, int c, vector<int> &cuts)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    int ans, subAns, size;

    for (int l = n; l >= 0; l--)
    {
        for (int r = 0; r <= n; r++)
        {
            ans = INT_MAX;
            subAns = INT_MAX;
            size = r - l;

            for (auto i : cuts)
            {
                if (i > l and i < r)
                {
                    subAns = size + dp[l][i] + dp[i][r];
                    ans = min(ans, subAns);
                }
            }
            if (ans == INT_MAX)
                ans = 0;

            dp[l][r] = ans;
        }
    }

    return dp[0][n];
}

int main()
{

    return 0;
}