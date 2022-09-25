#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/minimum-money-required-before-transactions/discuss/2590024/Two-Cases
*/

class Solution
{
public:
    long long minimumMoney(vector<vector<int>> &a)
    {
        int n = a.size();
        long long loss = 0, maxCost = 0, maxCashback = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i][0] > a[i][1])
            {
                loss += a[i][0] - a[i][1];
                maxCashback = max(maxCashback, (long long)a[i][1]);
            }
            else
            {
                maxCost = max(maxCost, (long long)a[i][0]);
            }
        }

        return loss + max(maxCashback, maxCost);
    }
};

int main()
{

    return 0;
}