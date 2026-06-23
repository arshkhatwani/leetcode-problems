import sys
from bisect import bisect_left
from typing import List

"""
This is done using meet in the middle algorithm.

We divide the array into two halves and then we calculate the sums of all the subsets of the two halves.

Then we sort the sums of the second half and for each sum in the first half we binary search for the closest sum in the second half.

We return the minimum absolute difference between the sum of the first half and the sum of the second half.

TC: O(2^(n/2) * log(2^(n/2)))

Time complexity calculation based on constraints:
n = 40, half = 20
Generation: 2 · (20 · 2^20) ≈ 4 · 10^7
Sort + bisect: 2 · (2^20 · 20) ≈ 4 · 10^7
Total ≈ 8 · 10^7  (~10^8)

SC: O(2^(n/2))

"""

class Solution:
    def minAbsDifference(self, nums: List[int], goal: int) -> int:
        m = len(nums)
        mid = len(nums) // 2

        def getSums(i: int, j: int):
            n = j - i + 1
            sums = []

            for x in range(1 << n):
                mask = x
                idx = 0
                s = 0
                while mask:
                    if mask & 1 > 0:
                        s += nums[i + idx]
                    mask >>= 1
                    idx += 1
                sums.append(s)

            return sums

        arr1 = getSums(0, mid - 1)
        arr2 = getSums(mid, m - 1)
        arr2.sort()

        ans = sys.maxsize
        for s1 in arr1:
            diff = goal - s1
            idx = bisect_left(arr2, diff)
            if idx < len(arr2):
                subseqSum = s1 + arr2[idx]
                ans = min(ans, abs(goal - subseqSum))
            if idx > 0:
                subseqSum = s1 + arr2[idx - 1]
                ans = min(ans, abs(goal - subseqSum))

        return ans
