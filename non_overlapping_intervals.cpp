#include <bits/stdc++.h>
using namespace std;

/*
If any intervals overlap, we have to remove one of them.
By greedy approach, we will keep the one that ends first and remove the one that ends later.
Detailed explanation of logic: https://youtu.be/nONCGxWoUfM?si=bJ1TmCAxH9AvJnmn
*/

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][0], count = 0;
        for (auto interval : intervals)
        {
            int start = interval[0], end = interval[1];
            if (start >= prevEnd)
            {
                prevEnd = end;
            }
            else
            {
                count += 1;
                prevEnd = min(prevEnd, end);
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}