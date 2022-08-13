#include <bits/stdc++.h>
using namespace std;

/*
We first take two heaps minHeap and maxHeap

Everytime we add a number we check if maxHeap is empty or top of maxHeap is > num if that is true then we add the element to maxHeap
else we add the element to minHeap

Now if maxHeap is > than minHeap's size + 1 then we pop an element from maxHeap and add it to minHeap

And if maxHeap's size < minHeap's size then we pop an element from minHeap and add it to maxHeap

See the code to understand getMedian() function
*/

class MedianFinder
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    MedianFinder() {}

    void addNum(int num)
    {
        if (maxHeap.empty() or maxHeap.top() > num)
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (maxHeap.size() < minHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian()
    {
        if (minHeap.size() == maxHeap.size())
        {
            return minHeap.top() / 2.0 + maxHeap.top() / 2.0;
        }
        return maxHeap.top();
    }
};

int main()
{

    return 0;
}