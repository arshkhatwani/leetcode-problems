#include <bits/stdc++.h>
using namespace std;

/*
This algo is shortest job first cpu scheduling algorithm

First we sort the given tasks array with its enqueue time

Then enqueue the first task in the array and keep pushing all the tasks in a min heap whose enqueue time is <= current time

Then we pop the tasks from min heap (which maintains tasks with minimum processing time) and increment our current time with the popped item from min heap

See the code to understand in detail
*/

class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &a)
    {
        int n = a.size();
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n; i++)
            a[i].push_back(i);
        sort(a.begin(), a.end());
        long long curTime = a[0][0], i = 0;

        while (i < n or !pq.empty())
        {
            if (i < n and a[i][0] <= curTime)
            {
                pq.push({a[i][1], a[i][2]});
                i++;
            }
            else if (!pq.empty())
            {
                int newTask = pq.top().first, idx = pq.top().second;
                ans.push_back(idx);
                curTime += newTask;
                pq.pop();
            }
            else // if there is no task to process then we skip our current time to the upcoming enqueue time
            {
                curTime = max(curTime, (long long)a[i][0]);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}