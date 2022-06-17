#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/sliding-window-maximum/discuss/1780396/C%2B%2B-or-Priority-Queue-and-Map

We are storing the elements in priority queue (max heap) and map and removing from the map as we move our sliding window forward.
In every iteration we are checking for the presence of the max element of our Heap in the Map:
If the element is present we are pushing it in the ans array.
Else we are popping out the max element of the Heap.
 */

// vector<int> maxSlidingWindow(vector<int> &a, int k)
// {
//     int n = a.size();
//     unordered_map<int, int> map;
//     priority_queue<int> pq;
//     vector<int> ans;

//     for (int i = 0; i < k; i++)
//     {
//         map[a[i]]++;
//         pq.push(a[i]);
//     }

//     int i = 0, j = k - 1;

//     while (j < n)
//     {
//         int maxEl = pq.top();
//         // If the element is present we are adding it in ans array and moving forward
//         if (map[maxEl] > 0)
//         {
//             ans.push_back(pq.top());
//             map[a[i]]--;
//             i++;
//             j++;
//             if (j < n)
//             {
//                 map[a[j]]++;
//                 pq.push(a[j]);
//             }
//         }
//         // Else we are popping the element
//         else
//         {
//             pq.pop();
//         }
//     }

//     return ans;
// }

/*
Another approach
https://leetcode.com/problems/sliding-window-maximum/discuss/1780485/C%2B%2B-or-Deque
We are creating a Deque which will store indices of the useful elements and will maintain the decreasing order of values.
For every element, the previous smaller elements are useless so we remove them from back,
And add front element to the ans array in every iteration and remove it from Deque.

Watch video here: https://youtu.be/MCvGwtkqJS0
 */

vector<int> maxSlidingWindow(vector<int> &a, int k)
{
    int n = a.size();
    deque<int> dq;
    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        // Removing useless elements (which are small than the currently added element)
        while (!dq.empty() and a[dq.back()] <= a[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    for (int i = k; i < n; i++)
    {
        ans.push_back(a[dq.front()]);

        // Removing elements which are out of the window
        while (!dq.empty() and dq.front() <= i - k)
            dq.pop_front();

        // Removing useless elements (which are small than the currently added element)
        while (!dq.empty() and a[dq.back()] <= a[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    // Adding element of the last window
    ans.push_back(a[dq.front()]);

    return ans;
}

int main()
{

    return 0;
}