#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);

        // we do this with smaller array
        int low = 0, high = n, cut1, cut2, l1, l2, r1, r2;

        while (low <= high)
        {
            cut1 = low + (high - low) / 2;
            cut2 = (n + m + 1) / 2 - cut1;

            l1 = cut1 > 0 and cut1 <= n ? nums1[cut1 - 1] : INT_MIN;
            r1 = cut1 >= 0 and cut1 < n ? nums1[cut1] : INT_MAX;

            l2 = cut2 > 0 and cut2 <= m ? nums2[cut2 - 1] : INT_MIN;
            r2 = cut2 >= 0 and cut2 < m ? nums2[cut2] : INT_MAX;

            if (l1 <= r2 and l2 <= r1)
            {
                if ((n + m) % 2 == 0)
                {
                    return (max(l1, l2) / 2.0 + min(r1, r2) / 2.0);
                }
                return max(l1, l2);
            }
            else if (l1 > r2)
            { // decrease l1
                high = cut1 - 1;
            }
            else if (l2 > r1)
            { // increase r1
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};

int main()
{

    return 0;
}