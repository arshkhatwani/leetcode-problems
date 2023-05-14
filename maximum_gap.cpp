#include <bits/stdc++.h>
using namespace std;

// This can be solved using Radix Sort: https://youtu.be/Il45xNUHGp0

class Solution
{
    void countSort(vector<int> &nums, int pos)
    {
        int n = nums.size();
        vector<int> count(10, 0), output(n, 0);

        for (int i = 0; i < n; i++)
        {
            int digit = (nums[i] / pos) % 10;
            count[digit]++;
        }

        for (int i = 1; i < 10; i++)
        {
            count[i] += count[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int digit = (nums[i] / pos) % 10;
            output[--count[digit]] = nums[i];
        }

        nums = output;
    }
    void radixSort(vector<int> &nums)
    {
        int n = nums.size(), maxi = nums[0];
        for (int i = 1; i < n; i++)
        {
            maxi = max(maxi, nums[i]);
        }

        for (int pos = 1; maxi / pos > 0; pos *= 10)
        {
            countSort(nums, pos);
        }
    }

public:
    int maximumGap(vector<int> &nums)
    {
        radixSort(nums);
        int n = nums.size(), diff = 0;

        for (int i = 0; i < n - 1; i++)
        {
            diff = max(diff, nums[i + 1] - nums[i]);
        }

        return diff;
    }
};

int main()
{

    return 0;
}