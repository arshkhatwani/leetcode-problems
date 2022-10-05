#include <bits/stdc++.h>
using namespace std;

/*
Greedy approach
Sort the array in increasing order
Calculate suffix sum and suffix product (a[i] * (i+1))
And iterate from left to right and keep track of answer and reduce suffix product by suffix sum and reduce suffix sum by a[i]

We can also,
Sort array in decreasing order
keep track of the prefix sum and total like time coeff
And we can keep iterating and updating prefix sum and adding it to total like time coeff and maximising our answer
https://leetcode.com/problems/reducing-dishes/discuss/563326/O(N*Log(N))-Time-O(1)-Space-Greedy-%2B-Prefix-Sum-%2B-Explanation
*/

// Approach 2
class Solution
{
public:
    int maxSatisfaction(vector<int> &a)
    {
        int n = a.size();
        int ans = 0, prefixSum = 0, totalLike = 0;

        sort(a.begin(), a.end(), greater<int>());

        for (int i = 0; i < n; i++)
        {
            prefixSum += a[i];
            totalLike += prefixSum;
            ans = max(ans, totalLike);
        }

        return ans;
    }
};

// Approach 1
class Solution
{
public:
    int maxSatisfaction(vector<int> &a)
    {
        int n = a.size();
        int suffixSum = 0, suffixPro = 0, ans = 0;

        sort(a.begin(), a.end());

        for (int i = n - 1; i >= 0; i--)
        {
            suffixSum += a[i];
            suffixPro += a[i] * (i + 1);
        }

        for (int i = 0; i < n; i++)
        {
            ans = max(ans, suffixPro);

            suffixPro -= suffixSum;
            suffixSum -= a[i];
        }

        return ans;
    }
};

int main()
{

    return 0;
}