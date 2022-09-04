#include <bits/stdc++.h>
using namespace std;

/*
Since we have to find the consecutive number of robots, we can solve this question using two pointers
Take 2 pointers i, j at 0. Take a decreasing multiset to keep track of the maximum chargeTime and take a sum variable to keep track of the cost

If the current chargeTime and cost is <= budget then we increment j pointer and after incrementing if j < n(array size) then we add runningCosts[j] to our costSum and insert the chargeTimes[j] to our multiset

Else we will remove the chargeTimes[i] from multiset and subtract runningCosts[i] from costSum and increment the ith pointer

If in any scenario j < i, we will set j = i and we add runningCosts[j] to our costSum and insert the chargeTimes[j] to our multiset
*/

class Solution
{
public:
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts, long long budget)
    {
        multiset<int, greater<int>> maxChargeTime;

        int n = chargeTimes.size(), i = 0, j = 0;

        maxChargeTime.insert(chargeTimes[i]);
        long long costSum = runningCosts[i];

        int ans = 0;

        while (i < n and j < n)
        {
            if (i > j)
            {
                j = i;
                costSum += runningCosts[j];
                maxChargeTime.insert(chargeTimes[j]);
            }

            int k = j - i + 1;
            long long maxTime = *(maxChargeTime.begin());

            if (maxTime + k * costSum <= budget)
            {
                ans = max(ans, k);

                j++;
                if (j < n)
                {
                    maxChargeTime.insert(chargeTimes[j]);
                    costSum += runningCosts[j];
                }
            }
            else
            {
                auto itr = maxChargeTime.find(chargeTimes[i]);
                if (itr != maxChargeTime.end())
                    maxChargeTime.erase(itr);
                costSum -= runningCosts[i];
                i++;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}