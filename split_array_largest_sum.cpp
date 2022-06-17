#include <bits/stdc++.h>
using namespace std;

/*
Dynamic Programming

The idea is to recursively split the given array and calculate the maximum sum among them and return minimum of these answers.
Like for m subarrays, we would split and call the function for m - 1 subarrays from the next index at which we split.
There would be a special/base case for m = 1, like if m = 1 then we dont need to split it further, hence we would only return the sum of the array
Basically recursively partition karna hai humko, you can see it in recurrence image

There would be overlapping subproblems containing idx and m so we will memoise it using n x m 2d array

TC : O(n^2 x m)
SC : O(n x m)

The recurrence would be like this,
f(idx, m){
    n = size of array
    sum = 0, subAns = 0, ans = 0
    for(i from idx to n - m + 1){
        sum += a[i]
        subAns = max(sum, f(i+1, m - 1))
        ans = max(subAns)
    }

    if(m == 1) return sum
    return ans
}
*/

// Memoisation
class Solution
{
private:
    vector<vector<int>> dp;
    int f(int idx, vector<int> &a, int m)
    {
        if (m == 0)
            return 0;

        if (dp[idx][m] != -1)
            return dp[idx][m];

        int n = a.size(), sum = 0, ans = INT_MAX, subAns;

        for (int i = idx; i < n - m + 1; i++)
        {
            sum += a[i];

            subAns = max(sum, f(i + 1, a, m - 1));

            ans = min(ans, subAns);
        }

        if (m == 1)
            ans = sum;

        return dp[idx][m] = ans;
    }

public:
    int splitArray(vector<int> &a, int m)
    {
        int n = a.size();

        dp = vector<vector<int>>(n, vector<int>(m + 1, -1));

        return f(0, a, m);
    }
};

// Tabulation
class Solution
{
public:
    int splitArray(vector<int> &a, int m)
    {
        int n = a.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int j = 1; j <= m; j++)
        {

            for (int idx = n - 1; idx >= 0; idx--)
            {

                int sum = 0, ans = INT_MAX, subAns;

                for (int i = idx; i < n - j + 1; i++)
                {
                    sum += a[i];

                    subAns = max(sum, dp[i + 1][j - 1]);

                    ans = min(ans, subAns);
                }

                if (j == 1)
                    ans = sum;

                dp[idx][j] = ans;
            }
        }

        return dp[0][m];
    }
};

int main()
{

    return 0;
}