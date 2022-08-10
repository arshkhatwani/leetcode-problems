#include <bits/stdc++.h>
using namespace std;

/*
Instead of capturing surrounded regions
Capture everything except unsurrounded regions

So here we first go to all border cells (which are 'O') and DFS from there to the 'O' cells and set their value to 'T' (temporarily)

Then we iterate the matrix and set all 'O' cells to 'X'
and we set all 'T' cells back to 'O'

Hence we have our answer

Watch video to understand in detail: https://youtu.be/9z2BunfoZ5Y
*/

class Solution
{
    void dfs(vector<vector<char>> &a, int i, int j)
    {
        if (i >= a.size() or j >= a[0].size() or i < 0 or j < 0)
            return;
        if (a[i][j] == 'X' or a[i][j] == 'T')
            return;

        a[i][j] = 'T';

        dfs(a, i + 1, j);
        dfs(a, i, j + 1);
        dfs(a, i - 1, j);
        dfs(a, i, j - 1);
    }

public:
    void solve(vector<vector<char>> &a)
    {
        int m = a.size(), n = a[0].size();

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
                if (a[i][j] == 'O')
                    a[i][j] = 'X';
                if (a[i][j] == 'T')
                    a[i][j] = 'O';
            }
        }
    }
};

int main()
{

    return 0;
}