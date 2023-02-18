#include <bits/stdc++.h>
using namespace std;

/*
Brute Force Approach:
We can do DFS from each and every cell in all four directions till we find an increasing path and keep track of the maximum/longest increasing path in a variable

Memoisation Approach:
In the above approach the cells will be getting visited/traversed multiple times, hence we can say that this problem has overlapping subproblems property

So we can keep a visited array/matrix of size same as given matrix and keep track of the longest increasing path from that particular cell, so that if the cell is occured again during some path calculation we can directly return the memoised value instead of traversing again from that cell

See the code to understand
Also, following post can be referred https://leetcode.com/problems/longest-increasing-path-in-a-matrix/solutions/3049569/java-dfs-with-memoization/
*/

class Solution
{
    int maxOf4(int a, int b, int c, int d)
    {
        return max(max(a, b), max(c, d));
    }
    int dfs(vector<vector<int>> &a, int i, int j, vector<vector<int>> &vis)
    {
        if (vis[i][j])
            return vis[i][j];

        int m = a.size(), n = a[0].size();
        int choice1 = 1, choice2 = 1, choice3 = 1, choice4 = 1;

        if (i + 1 < m and a[i + 1][j] > a[i][j])
            choice1 = 1 + dfs(a, i + 1, j, vis);
        if (i - 1 >= 0 and a[i - 1][j] > a[i][j])
            choice2 = 1 + dfs(a, i - 1, j, vis);
        if (j + 1 < n and a[i][j + 1] > a[i][j])
            choice3 = 1 + dfs(a, i, j + 1, vis);
        if (j - 1 >= 0 and a[i][j - 1] > a[i][j])
            choice4 = 1 + dfs(a, i, j - 1, vis);

        vis[i][j] = maxOf4(choice1, choice2, choice3, choice4);

        return vis[i][j];
    }

public:
    int longestIncreasingPath(vector<vector<int>> &a)
    {
        int m = a.size(), n = a[0].size(), ans = 1;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dfs(a, i, j, visited);
                ans = max(ans, visited[i][j]);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}