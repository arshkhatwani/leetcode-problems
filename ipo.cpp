#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
We can only get profits whose capitals are less than or equal to our current captial

Approach:
- Sort the array on the basis of captials in ascending order
- Then keep adding profits to a max heap till the capitals associated with those profits are less than or equal to our current captial
- Now when we are unable to add profits, we can pop an item to queue and add to our current capital then repeat the above step if its possible

We will stop the algorithm if k gets to 0 or if the heap gets empty and we cannot add it further

The value of our current captial will be the answer
*/

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        int n = profits.size();
        priority_queue<int> pq;

        vector<vector<int>> a;
        for (int i = 0; i < n; i++)
        {
            a.push_back({capital[i], profits[i]});
        }
        sort(a.begin(), a.end());

        int i = 0;
        while (k)
        {
            if (i < n and w >= a[i][0])
            {
                pq.push(a[i][1]);
                i++;
            }
            else if (!pq.empty())
            {
                w += pq.top();
                pq.pop();
                k--;
            }
            else
                break;
        }

        return w;
    }
};

int main()
{

    return 0;
}