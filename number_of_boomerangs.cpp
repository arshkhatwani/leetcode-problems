#include <bits/stdc++.h>
using namespace std;

/*
The idea is for every point we calculate the distance from all other points and we keep a track of the count of points at a particular distance (say x) in a map with x as key and value as the count of points at a distance x from the current iteration point

And then we iterate the map and see that if a count (value) is greater than 1 then we add nP2 (where n = count or value) to the answer

Here we are calculating and storing squared distance as we dont want to get to hassle of calculating doubles(decimals)
nP2 = n * (n - 1)
*/

class Solution
{
    long dist(vector<int> &a, vector<int> &b)
    {
        return pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2);
    }

public:
    int numberOfBoomerangs(vector<vector<int>> &a)
    {
        unordered_map<long, int> mp;
        int ans = 0;

        for (int i = 0; i < a.size(); i++)
        {
            mp.clear();

            for (int j = 0; j < a.size(); j++)
            {
                if (i == j)
                    continue;

                long d = dist(a[i], a[j]);
                mp[d]++;
            }

            for (auto i : mp)
            {
                if (i.second > 1)
                    ans += i.second * (i.second - 1);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}