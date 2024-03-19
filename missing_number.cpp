#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size(), ans = 0;
        int listXor = 0, totalXor = 0;

        for (int i = 0; i <= n; i++)
        {
            totalXor ^= i;
            if (i < n)
                listXor ^= nums[i];
        }

        return totalXor ^ listXor;
    }
};

int main()
{

    return 0;
}