#include <bits/stdc++.h>
using namespace std;

/*
We can go to every cell by BFS and mark each visited cell with '+' (which is given as wall and can't be visited)

We will keep track of the cost associated with every cell in the visitation queue

Once we reach a boundary cell we know it is the most minimum answer we can get as we reached there first. So we return that answer

If whole BFS is completed and we still haven't reached to boundary cell then we return -1 as we know its impossible
*/

class Solution
{
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    int nearestExit(vector<vector<char>> &a, vector<int> &entrance)
    {
        int m = a.size(), n = a[0].size();
        queue<vector<int>> q;
        q.push({entrance[0], entrance[1], 0});
        a[entrance[0]][entrance[1]] = '+';

        while (!q.empty())
        {
            int i = q.front()[0], j = q.front()[1], cost = q.front()[2];
            q.pop();

            for (auto k : dir)
            {
                int newI = i + k[0], newJ = j + k[1];

                if (newI >= 0 and newI < m and newJ >= 0 and newJ < n and a[newI][newJ] == '.')
                {
                    if (newI == 0 or newI == m - 1 or newJ == 0 or newJ == n - 1)
                    {
                        return cost + 1;
                    }
                    a[newI][newJ] = '+';
                    q.push({newI, newJ, cost + 1});
                }
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}