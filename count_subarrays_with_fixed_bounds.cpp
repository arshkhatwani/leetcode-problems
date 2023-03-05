#include <bits/stdc++.h>
using namespace std;

/*
The idea is so keep track of the subarrays in which all the elements are in the range [minK, maxK] along with track of a bound which represents the elements outside the range

For every element if that element lies in the range we update the recent positions of minK, maxK and also count the subarrays getting formed with those positions of minK, maxK and leftBound

if the array element does not fall in the range then we set the leftBound to that index and reset the varibles containing recent positions of minK and maxK

The count of subarrrays will be the difference between minimum of recent position of minK and maxK and leftBound

Refer to understand in detail: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/solutions/3254003/day-63-two-pointer-o-n-time-and-o-1-space-easiest-beginner-friendly-sol/
*/

class Solution
{
public:
    long long countSubarrays(vector<int> &a, int minK, int maxK)
    {
        int n = a.size();
        long long ans = 0;
        int lastMin = -1, lastMax = -1, leftBound = -1;

        for (int i = 0; i < n; i++)
        {
            if (a[i] >= minK and a[i] <= maxK)
            {
                if (a[i] == minK)
                    lastMin = i;
                if (a[i] == maxK)
                    lastMax = i;

                ans += max(0, min(lastMin, lastMax) - leftBound);
            }
            else
            {
                leftBound = i;
                lastMin = lastMax = -1;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}