#include <bits/stdc++.h>
using namespace std;

/*
The idea is to calculate prefix sum and store its frequency in the map

So, while calculating prefix sum we need to see for two conditions
1. We get prefix sum = k, in this case we increment out answer by 1
2. We need to check if there exists a key equal to (prefixSum - k) present in the map, if there is present then we will add its frequency (value in the map) to our answer

The purpose of 2nd condition is that if there already exists a sum 'x' in the map and if we subtract 'x' from prefixSum we get k (Because x = prefixSum - k). This tells us there exists a subarray whose sum on subtracting from current prefixSum will give us k

To elaborate, lets say we are at index 'j' (subarray 0->j) and there is a subarray ending at index 'i' (subarray 0->i) where i < j
AND
sum of subarray at j (i.e current prefixSum) - sum of subarray of i (i.e prefixSum - k) = k. This tells us that there exists a subarray(i+1->j) whose sum is k. So we count this subarray also in our answer

Read this to know more: https://leetcode.com/problems/subarray-sum-equals-k/discuss/1759909/C%2B%2Bor-Full-explained-every-step-w-Dry-run-or-O(n2)-greater-O(n)-or-Two-approaches
Or watch something on youtube
*/

class Solution
{
public:
    int subarraySum(vector<int> &a, int k)
    {
        int sum = 0, n = a.size(), count = 0;
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
        {
            sum += a[i];

            if (sum == k)
                count++;
            if (map[sum - k])
                count += map[sum - k];

            map[sum]++;
        }

        return count;
    }
};

int main()
{

    return 0;
}