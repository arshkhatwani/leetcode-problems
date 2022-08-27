#include <bits/stdc++.h>
using namespace std;

/*
We need to use the concept of Kadane's algo on matrices, here we dont need to find any submatrix/rectangle whose sum is maximum here we have a restriction that the maximum sum should be no mor than k

For this every time we calculate the maximum sum we will take a set(ordered set) and we will put the curSum in it

We will also do binary search(lower bound) for (curSum - k) if we find a value we will compare our maxSum with (curSum-value) and store the maximum to the maxSum

We will do the above process everytime we try to find maxSum and whenever we get maxSum as k we return k as answer this would help us save time

TC: O(n2 * m * logm)
SC: O(m) + O(m)

Read this to understand in detail: https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/discuss/83599/Accepted-C%2B%2B-codes-with-explanation-and-references
*/

class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>> &a, int k)
    {
        int m = a.size(), n = a[0].size(), ans = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            vector<int> sums(m, 0);

            for (int j = i; j < n; j++)
            {
                for (int row = 0; row < m; row++)
                {
                    sums[row] += a[row][j];
                }

                set<int> st;
                st.insert(0);
                int curSum = 0, maxSum = INT_MIN;
                for (int i = 0; i < m; i++)
                {
                    curSum += sums[i];

                    auto it = st.lower_bound(curSum - k);
                    if (it != st.end())
                        maxSum = max(maxSum, curSum - *it);

                    if (maxSum == k)
                        return maxSum;

                    st.insert(curSum);
                }
                ans = max(ans, maxSum);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}