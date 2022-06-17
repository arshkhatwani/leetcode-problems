#include <bits/stdc++.h>
using namespace std;

/*
for a set of 3 points lying on a same line their slope should be same

So i thought of calculating slope for first 2 points then for every point we calculate the slope and if it is != prev slope then we increase our ans by 1(initially 1)

But here 'double' data type was creating an issue idk why

So we used the tactic of cross multiplication

like if there are 3 pts (x1,y1) (x2,y2) (x3,y3)
we want to check if (y2-y1)/(x2-x1) == (y3-y2)/(x3-x2)
so here instead of dividing and checking we can also check (y3 - y2) * (x2 - x1) == (y2 - y1) * (x3 - x2)

we can start the iteration from i = 2 and we can take 3 points current, prev, before prev and we do the above comparison if they aren't equal then we increase our ans by 1
*/

class Solution
{
public:
    int minimumLines(vector<vector<int>> &a)
    {
        int n = a.size();

        if (n == 1)
            return 0;
        if (n == 2)
            return 1;

        sort(a.begin(), a.end());
        int ans = 1;
        long long x1, x2, x3, y1, y2, y3;
        long long s1, s2;

        for (int i = 2; i < n; i++)
        {
            x1 = a[i - 2][0], x2 = a[i - 1][0], x3 = a[i][0];
            y1 = a[i - 2][1], y2 = a[i - 1][1], y3 = a[i][1];

            s1 = (y3 - y2) * (x2 - x1);
            s2 = (y2 - y1) * (x3 - x2);

            if (s1 != s2)
            {
                ans++;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}