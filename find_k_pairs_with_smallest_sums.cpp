#include <bits/stdc++.h>
using namespace std;

/*
Take a min heap and push the pair of 1st elements (along with their sum as first element) for both the arrays
Also record this pair in a set
Now repeat until k pairs are collected and the min heap is not empty
    pop the pair from the queue
    add the pair to the answer
    from the popped pair (say {i, j}) if {i + 1, j} exists and is not recorded push it into min heap along with its sum and record it
    and if {i, j + 1} exists and is not recorded push it into min heap along with its sum and record it
*/

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        int m = nums1.size(), n = nums2.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> ans;
        set<vector<int>> s;

        pq.push({nums1[0] + nums2[0], 0, 0});
        while (k-- and !pq.empty())
        {
            vector<int> a = pq.top();
            pq.pop();

            int i = a[1], j = a[2];
            ans.push_back({nums1[i], nums2[j]});

            if (i + 1 < m and s.find({i + 1, j}) == s.end())
            {
                pq.push({nums1[i + 1] + nums2[j], i + 1, j});
                s.insert({i + 1, j});
            }
            if (j + 1 < n and s.find({i, j + 1}) == s.end())
            {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
                s.insert({i, j + 1});
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}