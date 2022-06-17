#include <bits/stdc++.h>
using namespace std;

/*
The following is a Greedy Approach

Basically what we are doing that we are sorting the points array and we are iterating it and keeping a track of interval our arrows can burst in a variable.
At every iteration we check that the current interval is intersecting our stored interval or not
If it is intersecting then we replace our stored interval with the intersection interval of (stored interval and current interval)
Else we increase our arrow count and replace our stored interval with the current interval
*/

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end());

        // cout << points.size() << endl;

        vector<int> last = {0, 0};
        int count = 0;
        for (int i = 0; i < points.size(); i++)
        {
            if (i == 0 or last[1] < points[i][0])
            {
                count++;
                last = points[i];
            }
            else
            {
                last[0] = max(last[0], points[i][0]);
                last[1] = min(last[1], points[i][1]);
            }
        }

        return count;
    }
};

int main()
{

    return 0;
}