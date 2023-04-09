#include <bits/stdc++.h>
using namespace std;

/*
Refer: https://leetcode.com/problems/make-k-subarray-sums-equal/solutions/3366373/k-cycles/
*/

class Solution
{
public:
    long long makeSubKSumEqual(vector<int> &a, int k)
    {
        int n = a.size();
        long long count = 0;

        for (int i = 0; i < k; i++)
        {
            vector<int> cycle;
            for (int j = i; a[j] != 0; j = (j + k) % n)
            {
                cycle.push_back(a[j]);
                a[j] = 0;
            }

            nth_element(cycle.begin(), cycle.begin() + cycle.size() / 2, cycle.end());
            for (auto k : cycle)
            {
                int mid = cycle[cycle.size() / 2];
                count += abs(mid - k);
            }
        }

        return count;
    }
};

int main()
{

    return 0;
}