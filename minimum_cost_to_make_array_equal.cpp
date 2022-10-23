#include <bits/stdc++.h>
using namespace std;

/*
Intuition & Approach based on DP prefix sum
You are not required a good math to come up with this solution in the contest.

We can construct two DP array where left2right[i] is the cost for increasing the elements which cost less than nums[i] to nums[i] (nums is sorted), and right2left[i] is the cost for decreasing the elements which cost greater than nums[i] to nums[i].

To compute the DP array. Forleft2right[i] we can cost left2right[i-1] to increase every element before i to nums[i-1], then cost (nums[i] - nums[i-1]) * sum(cost[0 ~ i-1]) to increase all of them to nums[i]. Similar for right2left.

Finally, the result will be the minimum of left2right[i] + right2left[i], for 0 <= i < n.

Reference: https://leetcode.com/problems/minimum-cost-to-make-array-equal/discuss/2734625/DP-Solution.-Intuitive-and-Clear-or-Python
*/

class Solution
{
public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        int n = nums.size();
        vector<long long> left2Right(n, 0), right2Left(n, 0);
        vector<vector<int>> a;

        for (int i = 0; i < n; i++)
        {
            a.push_back({nums[i], cost[i]});
        }

        sort(a.begin(), a.end());

        long long totalCost = a[0][1], ans = 1e18;
        for (int i = 1; i < n; i++)
        {
            long long diff = a[i][0] - a[i - 1][0];

            left2Right[i] = left2Right[i - 1] + totalCost * diff;

            totalCost += a[i][1];
        }

        totalCost = a[n - 1][1];
        for (int i = n - 2; i >= 0; i--)
        {
            long long diff = a[i + 1][0] - a[i][0];

            right2Left[i] = right2Left[i + 1] + totalCost * diff;

            totalCost += a[i][1];
        }

        for (int i = 0; i < n; i++)
        {
            ans = min(ans, left2Right[i] + right2Left[i]);
        }

        return ans;
    }
};

int main()
{

    return 0;
}