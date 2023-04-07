#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int dfs(int i, int j, vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        if (i == 0 or i == m - 1 or j == 0 or j == n - 1)
            return grid[i][j];
        if (grid[i][j] == 1)
            return 1;

        grid[i][j] = 1;

        int left = dfs(i, j - 1, grid);
        int right = dfs(i, j + 1, grid);
        int top = dfs(i - 1, j, grid);
        int down = dfs(i + 1, j, grid);

        return left and right and top and down;
    }

public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;

        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (grid[i][j])
                    continue;

                count += dfs(i, j, grid);
            }
        }

        return count;
    }
};

int main()
{

    return 0;
}