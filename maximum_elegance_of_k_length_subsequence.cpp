#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long findMaximumElegance(vector<vector<int>> &a, int k)
    {
        sort(a.begin(), a.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[0] > b[0]; });
        int n = a.size();
        long long ans = 0, curSum = 0;
        vector<int> dup;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            if (i < k)
            {
                if (mp.find(a[i][1]) != mp.end())
                {
                    dup.push_back(a[i][0]);
                }
                curSum += a[i][0];
            }
            else if (mp.find(a[i][1]) == mp.end())
            {
                if (dup.empty())
                    break;
                curSum += (a[i][0] - dup.back());
                dup.pop_back();
            }
            mp[a[i][1]] += 1;
            ans = fmax(ans, curSum + 1L * mp.size() * mp.size());
        }

        return ans;
    }
};

int main()
{

    return 0;
}