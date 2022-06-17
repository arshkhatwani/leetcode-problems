#include <bits/stdc++.h>
using namespace std;

/*
The brute force approach would be to take every cell in matrix and dfs/bfs it and find if the search has reached both the oceans or not but this would take too long
TC: O((mn)^2)

The better approach would be to dfs/bfs from the edge cells of the matrix which are directly beside the oceans and keep 2 visited ocean arrays to check if the search reaches that cell or not and we would only do these searches whose height would be greater than equal to height of the edge cells as we are going in reverse direction in this case
TC: O(mn)
SC: O(mn)
*/

// BFS
class Solution
{
    void bfs(int src, int i, int j, vector<vector<int>> &a, vector<vector<int>> &visited)
    {
        if (visited[i][j])
            return;

        int m = a.size(), n = a[0].size();
        visited[i][j] = 1;

        queue<pair<int, int>> q;
        q.push({i, j});

        vector<vector<int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!q.empty())
        {
            int x = q.front().first, y = q.front().second;
            q.pop();

            for (auto k : d)
            {
                int newI = x + k[0], newJ = y + k[1];

                if (newI < m and newI >= 0 and newJ < n and newJ >= 0)
                {
                    if (a[newI][newJ] >= a[x][y] and !visited[newI][newJ])
                    {
                        visited[newI][newJ] = 1;
                        q.push({newI, newJ});
                    }
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &a)
    {
        int m = a.size(), n = a[0].size();
        vector<vector<int>> atlantic(m, vector<int>(n, 0)), pacific(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            bfs(a[i][0], i, 0, a, pacific);
            bfs(a[i][n - 1], i, n - 1, a, atlantic);
        }
        for (int j = 0; j < n; j++)
        {
            bfs(a[0][j], 0, j, a, pacific);
            bfs(a[m - 1][j], m - 1, j, a, atlantic);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] and atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};

// DFS
class Solution
{
    void dfs(int src, int i, int j, vector<vector<int>> &a, vector<vector<int>> &visited)
    {
        if (i < 0 or j < 0 or i == a.size() or j == a[0].size())
            return;
        if (src > a[i][j])
            return;
        if (visited[i][j])
            return;

        visited[i][j] = 1;

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (auto d : directions)
        {
            dfs(a[i][j], i + d[0], j + d[1], a, visited);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &a)
    {
        int m = a.size(), n = a[0].size();
        vector<vector<int>> atlantic(m, vector<int>(n, 0)), pacific(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            dfs(a[i][0], i, 0, a, pacific);
            dfs(a[i][n - 1], i, n - 1, a, atlantic);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(a[0][j], 0, j, a, pacific);
            dfs(a[m - 1][j], m - 1, j, a, atlantic);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] and atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}