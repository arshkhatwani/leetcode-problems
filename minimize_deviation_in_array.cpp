#include <bits/stdc++.h>
using namespace std;

/*
As we know that the deviation in array is the maximum absolute difference between 2 elements, so we can calculate this by taking the difference maximum and minimum value in the array

To minimise this difference we can try to increase the minimum value and decrease the maximum value

All the odd numbers can be transformed to even ones by multiplying them by 2 and keep track of a minimum element and push all these numbers into a maxheap

Then numbers can be popped from max heap, difference can be calculated and then we divide them by 2

After dividing them by 2 we can compare our minimum element with them to ensure our minimum element is maintained and we push them(after getting divided) again into the max heap

We keep tracking the minimimum difference calculated so far as that will be our answer

We do the following operation till we cannot divide the popped element
*/

class Solution
{
public:
    int minimumDeviation(vector<int> &a)
    {
        int n = a.size();
        int mini = INT_MAX;
        priority_queue<int> pq;

        for (auto i : a)
        {
            if (i % 2 == 1)
                i *= 2;
            mini = min(mini, i);
            pq.push(i);
        }

        int minDiff = INT_MAX;

        while (1)
        {
            int maxi = pq.top();
            pq.pop();
            minDiff = min(minDiff, maxi - mini);

            if (maxi % 2)
                break;
            else
                maxi /= 2;

            mini = min(mini, maxi);
            pq.push(maxi);
        }

        return minDiff;
    }
};

int main()
{

    return 0;
}