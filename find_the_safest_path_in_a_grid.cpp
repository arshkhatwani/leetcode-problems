#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> dis, visited;

    void bfs(int i, int j, vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;

        q.push({i, j});
        while (!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();

            for (auto d : dir)
            {
                pair<int, int> newP = {p.first + d.first, p.second + d.second};
                if (newP.first < 0 or newP.first >= m or newP.second < 0 or newP.second >= n)
                    continue;
                if (grid[newP.first][newP.second] == 1)
                    continue;

                int newDistance = abs(i - newP.first) + abs(j - newP.second);
                if (newDistance >= dis[newP.first][newP.second])
                    continue;

                dis[newP.first][newP.second] = newDistance;
                q.push(newP);
            }
        }
    }

    bool isValid(int threshold, int i, int j, int m, int n)
    {
        if (i < 0 or i >= m or j < 0 or j >= n)
            return false;
        if (visited[i][j])
            return false;
        if (dis[i][j] <= threshold)
            return false;
        if (i == m - 1 and j == n - 1)
            return true;

        visited[i][j] = 1;
        bool ans = false;
        for (auto d : dir)
        {
            ans = ans or isValid(threshold, i + d.first, j + d.second, m, n);
        }

        return ans;
    }

public:
    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        dis = vector<vector<int>>(m, vector<int>(n, INT_MAX));
        int low = 0, high = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    dis[i][j] = 0;
                    bfs(i, j, grid);
                }
                high = max(high, dis[i][j]);
            }
        }

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            visited = vector<vector<int>>(m, vector<int>(n, 0));

            if (isValid(mid, 0, 0, m, n))
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        return low;
    }
};

int main()
{

    return 0;
}