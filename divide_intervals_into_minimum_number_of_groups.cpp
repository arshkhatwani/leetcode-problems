#include <bits/stdc++.h>
using namespace std;

/*
This problem is similar to meeting rooms problem
We use a min heap to track the rightmost number of each group

First, we sort the intervals. Then, for each interval, we check if the top of the heap is greater than equal to left i.e if a meeting room (group) is in use or not.

If group(meeting room) in use, we need a new group(allot a new meeting room) push right into the heap.

If it is not, we can add that interval to an existing group(meeting room): pop from the heap, and push right, updating the rightmost number of that group.

In the end, the size of the heap(the total meeting rooms) is the number of groups we need.
*/

class Solution
{
public:
    int minGroups(vector<vector<int>> &a)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        sort(a.begin(), a.end());
        int n = a.size();

        for (int i = 0; i < n; i++)
        {
            int start = a[i][0], end = a[i][1];
            if (!pq.empty() and pq.top() >= start)
            {
                pq.push(end);
            }
            else
            {
                if (!pq.empty())
                    pq.pop();
                pq.push(end);
            }
        }

        return pq.size();
    }
};

int main()
{

    return 0;
}