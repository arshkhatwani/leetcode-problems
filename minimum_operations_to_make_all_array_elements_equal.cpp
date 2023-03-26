#include <bits/stdc++.h>
using namespace std;

// See hint to understand

class Solution
{
public:
    vector<long long> minOperations(vector<int> &nums, vector<int> &queries)
    {
        int n = nums.size();
        vector<long long> prefix(n, 0);

        sort(nums.begin(), nums.end());
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        int m = queries.size();
        vector<long long> ans(m, 0);

        for (int i = 0; i < m; i++)
        {
            long long q = queries[i];
            long long l = lower_bound(nums.begin(), nums.end(), q) - nums.begin();
            long long h = upper_bound(nums.begin(), nums.end(), q) - nums.begin();

            long long op1 = l > 0 ? (q * l) - prefix[l - 1] : 0;
            long long op2 = h > 0 ? (prefix[n - 1] - prefix[h - 1]) - (q * (n - h)) : prefix[n - 1] - (q * n);

            ans[i] = op1 + op2;
        }

        return ans;
    }
};

int main()
{

    return 0;
}