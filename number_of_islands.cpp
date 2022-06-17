#include <bits/stdc++.h>
using namespace std;

/*
Basically this probelm is the variation of the 'count the connected components' in a graph problem.
We are keeping a visited matrix that denotes that a particular node is visited or not

So now for every element in the matrix which is == '1' we can do a DFS on the node above it, below it, right of it, left of it, and record the nodes in visited array.

We initialise the count as 0.
Now for every element(i, j, grid[i][j]) in the grid if that element == '1' and that element is unvisited then we call DFS on that element and we increase the count every time we encounter a case like this while traversing the grid.

The count will be our answer
*/

/*
We can optimise space as the grid array looks similar to visited array
So when we encounter the node and when we call the DFS on the node, we can make the node == '0' now as we have already visited it and counted the component

So ese kar kar ke saare visited islands 0 hoke gayab hojayenge and fir bhi incase humko ek node esa milta hai jo == '1' hai wo humara dusra island hoga

Can watch this: https://youtu.be/o8S2bO3pmO4
*/

// class Solution
// {
//     vector<vector<int>> visited;

// private:
//     void dfs(int i, int j, vector<vector<char>> &grid)
//     {
//         if (i >= grid.size() or j >= grid[0].size())
//             return;
//         if (grid[i][j] == '0')
//             return;
//         if (visited[i][j] == 1)
//             return;
//         visited[i][j] = 1;

//         dfs(i + 1, j, grid);
//         dfs(i - 1, j, grid);
//         dfs(i, j + 1, grid);
//         dfs(i, j - 1, grid);
//     }

// public:
//     int numIslands(vector<vector<char>> &grid)
//     {
//         int m = grid.size(), n = grid[0].size(), count = 0;

//         visited = vector<vector<int>>(m, vector<int>(n, 0));

//         for (int i = 0; i < m; i++)
//         {
//             for (int j = 0; j < n; j++)
//             {
//                 if (grid[i][j] == '1' and visited[i][j] == 0)
//                 {
//                     dfs(i, j, grid);
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };

// O(1) space solution
class Solution
{
private:
    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        if (i >= grid.size() or j >= grid[0].size())
            return;
        if (grid[i][j] == '0')
            return;

        grid[i][j] = '0';

        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), count = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    count++;
                }
            }
        }

        return count;
    }
};

int main()
{

    return 0;
}