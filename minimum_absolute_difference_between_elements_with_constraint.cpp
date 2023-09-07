#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAbsoluteDifference(vector<int> &a, int x)
    {
        int n = a.size(), ans = INT_MAX;
        multiset<int> s;

        for (int i = x; i < n; i++)
        {
            s.insert(a[i]);
        }

        for (int i = 0; i < n; i++)
        {
            auto it = s.lower_bound(a[i]);
            if (it != s.end())
            {
                int el = *it;
                int diff = abs(a[i] - el);
                ans = min(ans, diff);
            }
            if (it != s.begin())
            {
                it--;
                int el = *it;
                int diff = abs(a[i] - el);
                ans = min(ans, diff);
            }
            if (i + x < n)
                s.erase(s.find(a[i + x]));
        }

        return ans;
    }
};

int main()
{

    return 0;
}