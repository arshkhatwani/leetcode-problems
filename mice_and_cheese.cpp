#include <bits/stdc++.h>
using namespace std;

// Refer 'hint'

class Solution
{
public:
    int miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k)
    {
        int n = reward1.size(), total = 0;
        priority_queue<int> pq;

        for (int i = 0; i < n; i++)
        {
            total += reward2[i];
            pq.push(reward1[i] - reward2[i]);
        }

        while (k--)
        {
            total += pq.top();
            pq.pop();
        }

        return total;
    }
};

int main()
{

    return 0;
}