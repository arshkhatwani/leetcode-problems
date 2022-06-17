#include <bits/stdc++.h>
using namespace std;

/*
The logic is to do BFS and rot oranges

Take a queue

First iterate in matrix and stor indices of every rotten orange
Push a dummy value (like {-1, -1}) like we push NULL in binary tree level order traversal
we are doing this because every minute fresh neighbours of rotten oranges get rotten simultaneously

Then till queue is not qmpty pop the front and rot its fresh neighbours and push them into the queue
if the popped element is the dummy one check if the queue is empty or not:
    if empty then do nothing
    else increment the answer and push the dummy element again

After the end of queue iteration, traverse the matrix and if you find any fresh orange return -1
After successful completion of traversal, return the answer
*/

class Solution
{
private:
    void rotOranges(vector<vector<int>> &grid, int i, int j, queue<pair<int, int>> &q)
    {
        if (i >= grid.size() or i < 0 or j >= grid[0].size() or j < 0)
            return;

        if (grid[i][j] == 1)
        {
            grid[i][j] = 2;
            q.push({i, j});
        }
    }

public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        q.push({-1, -1});

        int count = 0, i, j;

        while (!q.empty())
        {
            i = q.front().first, j = q.front().second;
            q.pop();

            if (i != -1 and j != -1)
            {
                rotOranges(grid, i + 1, j, q);
                rotOranges(grid, i, j + 1, q);
                rotOranges(grid, i - 1, j, q);
                rotOranges(grid, i, j - 1, q);
            }
            else
            {
                if (!q.empty())
                {
                    count++;
                    q.push({-1, -1});
                }
            }
        }

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return count;
    }
};

int main()
{

    return 0;
}