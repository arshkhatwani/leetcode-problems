#include <bits/stdc++.h>
using namespace std;

/*
INTUITION
We know that if any land can reach boundary land it can reach the boundary and will not be counted in our answer

APPROACH
We can dfs from every boundary land and eliminate all the lands/cells reachable from there (eliminate => make cell = 0)
The remaining 1s or lands will be our answer
*/

class Solution
{
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    void dfs(vector<vector<int>> &a, int i, int j)
    {
        int m = a.size(), n = a[0].size();

        if (i < 0 or j < 0 or i == m or j == n)
            return;
        if (a[i][j] == 0)
            return;

        a[i][j] = 0;
        for (auto k : dir)
        {
            dfs(a, i + k[0], j + k[1]);
        }
    }

public:
    int numEnclaves(vector<vector<int>> &a)
    {
        int m = a.size(), n = a[0].size(), count = 0;

        for (int i = 0; i < m; i++)
        {
            dfs(a, i, 0);
            dfs(a, i, n - 1);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(a, 0, j);
            dfs(a, m - 1, j);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                count += a[i][j];
            }
        }

        return count;
    }
};

int main()
{

    return 0;
}