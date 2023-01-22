#include <bits/stdc++.h>
using namespace std;

/*
The idea is to consider each element in nums2 as minimum and calculate the score

So we map the values in nums1 and nums2 and store it in the array and sort the array in descending order by nums2 values

Now we keep a min heap of maximum size k and calculate the score and keep track of the maximum one

See the code to understand more
*/

class Solution
{
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<pair<int, int>> a;
        int n = nums1.size();

        for (int i = 0; i < n; i++)
        {
            a.push_back({nums2[i], nums1[i]});
        }
        sort(a.rbegin(), a.rend());
        priority_queue<int, vector<int>, greater<int>> pq;

        long long sum = 0, ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x = a[i].first, y = a[i].second;
            pq.push(y);
            sum += y;

            if (pq.size() > k)
            {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k)
            {
                long long subAns = x * sum;
                ans = max(ans, subAns);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}