#include <bits/stdc++.h>
using namespace std;

/*
The logic of this problem is same as the problem "Subarray Product Less Than K" here instead of product we keep track of score (we can keep track of sum and we can multiply it by the subarray length to get score see the code)
*/

class Solution
{
public:
    long long countSubarrays(vector<int> &a, long long k)
    {
        int n = a.size();
        int i = 0, j = 0;
        long long sum = a[0], ans = 0;

        while (i < n and j < n)
        {
            if (sum * (j - i + 1) >= k)
            {
                sum -= a[i];
                i++;
                continue;
            }

            ans += j - i + 1;
            j++;
            if (j < n)
                sum += a[j];
        }

        return ans;
    }
};

int main()
{

    return 0;
}