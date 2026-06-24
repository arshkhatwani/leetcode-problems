import sys
from bisect import bisect_left
from typing import List

"""
This problem is similar to the closest subsequence sum problem.
"""


class Solution:
    def minimumDifference(self, nums: List[int]) -> int:
        def getSubarraySumsWithSize(i: int, j: int) -> List[List[int]]:
            n = j - i + 1
            res = [[] for _ in range(1 << n)]

            for mask in range(1 << n):
                s, idx, sz = 0, 0, 0
                while mask:
                    if mask & 1 > 0:
                        sz += 1
                        s += nums[i + idx]

                    idx += 1
                    mask >>= 1

                res[sz].append(s)

            return res

        n, totalSum = len(nums), sum(nums)
        mid = n // 2
        arr1 = getSubarraySumsWithSize(0, mid - 1)
        arr2 = getSubarraySumsWithSize(mid, n - 1)

        for arr in arr2:
            arr.sort()

        ans = sys.maxsize
        for sz in range(len(arr1)):
            for s1 in arr1[sz]:
                s2 = (totalSum - 2 * s1) // 2
                idx = bisect_left(arr2[mid - sz], s2)

                if idx < len(arr2[mid - sz]):
                    s2 = arr2[mid - sz][idx]
                    ans = min(ans, abs(totalSum - 2 * (s1 + s2)))
                if idx > 0:
                    s2 = arr2[mid - sz][idx - 1]
                    ans = min(ans, abs(totalSum - 2 * (s1 + s2)))

        return ans
