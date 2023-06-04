#include <bits/stdc++.h>
using namespace std;

// Sort the monsters by arrival time

// Solution 1
class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        for (int i = 0; i < n; i++)
        {
            dist[i] = (dist[i] - 1) / speed[i];
        }

        sort(dist.begin(), dist.end());

        for (int i = 0; i < n; i++)
        {
            if (i > dist[i])
                return i;
        }

        return n;
    }
};

// Solution 2
bool comp(pair<int, int> &a, pair<int, int> &b)
{
    int t1 = a.first % a.second == 0 ? a.first / a.second : a.first / a.second + 1;
    int t2 = b.first % b.second == 0 ? b.first / b.second : b.first / b.second + 1;
    return t1 < t2;
}

class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        vector<pair<int, int>> a;

        for (int i = 0; i < n; i++)
        {
            a.push_back({dist[i], speed[i]});
        }

        sort(a.begin(), a.end(), comp);

        int curTime = 0, count = 0;
        for (int i = 0; i < n; i++, curTime++)
        {
            int d = a[i].first, s = a[i].second;

            if (d - s * curTime > 0)
                count++;
            else
                break;
        }

        return count;
    }
};

int main()
{

    return 0;
}