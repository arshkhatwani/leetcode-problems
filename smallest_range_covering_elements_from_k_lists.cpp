#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    int row;
    int col;

    Node(int v, int r, int c)
    {
        val = v;
        row = r;
        col = c;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->val > b->val;
    }
};

/*
We first find minimum and maximum element among the first elements of each list and also push each of the first elements in a min heap along with their row,col values

Then we set min and max element as our answer

Then while min heap's size == k we pop the minimum element from the min heap and compare our minimum element with it

Then compare the min el and max el pair to our answer if this pair is smaller range then make this pair our answer

Now we increase the minimum element that we popped from the min heap, we do this by incrementing the col value and pushing the element present at (row, col) place in the given array
Here if col + 1 exceeds the list size then we do nothing

See video and code to understand more: https://youtu.be/RrxpTWqj97A
*/

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        int k = nums.size();
        int mini = INT_MAX, maxi = INT_MIN;
        priority_queue<Node *, vector<Node *>, compare> minHeap;

        for (int i = 0; i < k; i++)
        {
            mini = min(mini, nums[i][0]);
            maxi = max(maxi, nums[i][0]);

            Node *node = new Node(nums[i][0], i, 0);
            minHeap.push(node);
        }

        int start = mini, end = maxi;

        while (minHeap.size() == k)
        {
            Node *temp = minHeap.top();
            minHeap.pop();

            mini = temp->val;

            if (end - start > maxi - mini or (end - start == maxi - mini and mini < start))
            {
                start = mini;
                end = maxi;
            }

            if (temp->col + 1 < nums[temp->row].size())
            {
                int row = temp->row, col = temp->col + 1;
                Node *newNode = new Node(nums[row][col], row, col);

                maxi = max(maxi, nums[row][col]);

                minHeap.push(newNode);
            }
        }

        return {start, end};
    }
};

int main()
{

    return 0;
}