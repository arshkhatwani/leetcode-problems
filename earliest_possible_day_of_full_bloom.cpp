#include <bits/stdc++.h>
using namespace std;

/*
Upon observation:
- It doesn't matter when if we plant seeds according to their plant time
- Seed with high grow time should be planted before seed with low grow time

So we sort the seeds in decending order of the grow time
And we plant them and calculate time at which the seed will bloom
For this we need to calculate startTime(initially 0) this will be updated everytime we plant a seed

bloom time = current start time + plant time + grow time

next planting start time = current start time + plant time of current seed

The maximum of these bloom times will be our answer

TC: O(nlogn)
SC: O(n)
*/

class Solution
{
public:
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        vector<pair<int, int>> a;
        int n = plantTime.size();
        for (int i = 0; i < n; i++)
        {
            a.push_back({growTime[i], plantTime[i]});
        }
        sort(a.begin(), a.end(), greater<pair<int, int>>());

        int ans = 0, startTime = 0, bloomTime;
        for (int i = 0; i < n; i++)
        {
            int plant = a[i].second, grow = a[i].first;
            bloomTime = startTime + plant + grow;
            ans = max(ans, bloomTime);
            startTime += plant;
        }

        return ans;
    }
};

int main()
{

    return 0;
}