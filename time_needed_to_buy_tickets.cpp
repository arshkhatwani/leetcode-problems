#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/time-needed-to-buy-tickets/discuss/1576932/C%2B%2B-One-Pass
*/

// Brute Force O(sum(a))
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &a, int k)
    {
        int n = a.size(), ans = 0;

        while (1)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] == 0)
                    continue;
                a[i]--;
                ans++;
                if (a[k] == 0)
                    return ans;
            }
        }

        return 0;
    }
};

// Optimised O(n)
class Solution
{
public:
    int timeRequiredToBuy(vector<int> &a, int k)
    {
        int n = a.size(), ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (i <= k)
                ans += min(a[i], a[k]);
            else
                ans += min(a[i], a[k] - 1);
        }

        return ans;
    }
};

int main()
{

    return 0;
}