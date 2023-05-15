#include <bits/stdc++.h>
using namespace std;

/*
We know that a unique solution exists or nothing

If our total cost is less than 0 then we know no solution exists, we return -1 in this case

We keep a 'cur' variable to store our current gas, an 'ans' variable initially set to 0

So we keep adding (gas[i] - cost[i]) to the 'cur' variable and once 'cur'

So lets say at any index cur gets < 0 so we know that any station from 0 to i index is bad. So we set the answer to i + 1

At the end we check if total cost is < 0 we return -1
Else we return ans
*/

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size(), cur = 0, total = 0, ans = 0;

        for (int i = 0; i < n; i++)
        {
            total += (gas[i] - cost[i]);
            cur += (gas[i] - cost[i]);

            if (cur < 0)
            {
                ans = (i + 1) % n;
                cur = 0;
            }
        }

        if (total < 0)
            return -1;

        return ans;
    }
};

int main()
{

    return 0;
}