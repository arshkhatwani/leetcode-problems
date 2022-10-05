#include <bits/stdc++.h>
using namespace std;

/*
My Approach:
Recursively traverse in every direction and keep a bitmask to keep track of the cells visited and when reaching the end cell check if all the visitable cells in the grid are visited or not if yes return 1 else return 0
See the code to understand more

Another approach:
https://leetcode.com/problems/unique-paths-iii/discuss/221946/JavaPython-Brute-Force-Backtracking
*/

// My approach
class Solution
{
    int solve(vector<vector<int>> &grid, int i, int j, int bitmask, int &resultBitmask)
    {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 or i >= m or j < 0 or j >= n)
            return 0;
        if (grid[i][j] == -1)
            return 0;

        if (grid[i][j] == 2)
        {
            return resultBitmask == bitmask;
        }

        int maxPosInRow = (i + 1) * n;
        int pos = maxPosInRow - (n - j);

        if ((bitmask & 1 << pos) > 0)
            return 0;

        bitmask = bitmask | 1 << pos;

        int up = solve(grid, i - 1, j, bitmask, resultBitmask);
        int down = solve(grid, i + 1, j, bitmask, resultBitmask);
        int left = solve(grid, i, j - 1, bitmask, resultBitmask);
        int right = solve(grid, i, j + 1, bitmask, resultBitmask);

        return up + down + left + right;
    }

public:
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int startRow = -1, startCol = -1, bitmask = 0, resultBitmask = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    startRow = i;
                    startCol = j;
                }
                int maxPosInRow = (i + 1) * n;
                int pos = maxPosInRow - (n - j);

                if (grid[i][j] == 0 or grid[i][j] == 1)
                    resultBitmask = resultBitmask | 1 << pos;
            }
        }

        int ans = solve(grid, startRow, startCol, bitmask, resultBitmask);

        return ans;
    }
};

// Another approach
class Solution
{
    int dfs(vector<vector<int>> &a, int i, int j, int empty)
    {
        int m = a.size(), n = a[0].size();
        if (i < 0 or i >= m or j < 0 or j >= n)
            return 0;
        if (a[i][j] < 0)
            return 0;

        if (a[i][j] == 2)
        {
            return empty == 0;
        }

        empty--;
        a[i][j] = -2;

        int up = dfs(a, i - 1, j, empty);
        int down = dfs(a, i + 1, j, empty);
        int left = dfs(a, i, j - 1, empty);
        int right = dfs(a, i, j + 1, empty);

        a[i][j] = 0;

        return up + down + left + right;
    }

public:
    int uniquePathsIII(vector<vector<int>> &a)
    {
        int m = a.size(), n = a[0].size();
        int empty = 0, startRow = -1, startCol = -1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 0 or a[i][j] == 1)
                    empty++;

                if (a[i][j] == 1)
                {
                    startRow = i;
                    startCol = j;
                }
            }
        }

        return dfs(a, startRow, startCol, empty);
    }
};

int main()
{

    return 0;
}