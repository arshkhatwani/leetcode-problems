#include <bits/stdc++.h>
using namespace std;

/*
For maximising sum of array1 : sum1 = sum1 - sum of nums1 subarray + sum of nums2 subarray
For maximising sum of array1 : sum2 = sum2 - sum of nums2 subarray + sum of nums1 subarray

2 arrays can be formed: 1 => every ith element = nums1[i] - nums2[i]
                        2 => every ith element = nums2[i] - nums1[i]
We will try to find maximum subarray sum (lets assume it as k1 for 1st subarray and k2 for second) in both of these two arrays
and we would compute maximum score by comparing our existing maximum score value with the maximum of (sum1 + k2, sum2 + k1)
We will use Kadane's Algorithm for this

TC: O(n)
SC: O(1)

See the code to understand more
See this video to understand (just for logic and intuition): https://youtu.be/pYnSt44lZWM
*/

class Solution
{
public:
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int k1 = 0, k2 = 0, maxScore = 0, sum1 = 0, sum2 = 0;

        for (int i = 0; i < n; i++)
            sum1 += nums1[i], sum2 += nums2[i];

        for (int i = 0; i < n; i++)
        {
            k1 = max(k1 + nums1[i] - nums2[i], 0);
            k2 = max(k2 + nums2[i] - nums1[i], 0);

            maxScore = max(maxScore, max(sum1 + k2, sum2 + k1));
        }

        return maxScore;
    }
};

int main()
{

    return 0;
}