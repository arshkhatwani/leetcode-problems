#include <bits/stdc++.h>
using namespace std;

/*
The logic for this problem is same as https://leetcode.com/problems/maximum-subsequence-score/
*/

class Solution
{
public:
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        long long MOD = 1e9 + 7;
        vector<pair<int, int>> a;
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            a.push_back({efficiency[i], speed[i]});
        }
        sort(a.rbegin(), a.rend());

        for (int i = 0; i < n; i++)
        {
            int s = a[i].second, e = a[i].first;
            pq.push(s);
            sum += s;

            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }
            if (pq.size() <= k)
            {
                long long subAns = sum * (long long)e;
                ans = max(ans, subAns);
            }
        }

        return ans % MOD;
    }
};

int main()
{

    return 0;
}