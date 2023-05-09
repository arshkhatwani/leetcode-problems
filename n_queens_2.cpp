#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool check(vector<vector<int>> &a, int i, int j)
    {
        int n = a.size();

        for (int k = 0; k < n; k++)
        {
            if (a[k][j] or a[i][k])
                return false;
        }

        for (int x = i, y = j; x < n and y < n; x++, y++)
        {
            if (a[x][y])
                return false;
        }

        for (int x = i, y = j; x >= 0 and y >= 0; x--, y--)
        {
            if (a[x][y])
                return false;
        }

        for (int x = i, y = j; x < n and y >= 0; x++, y--)
        {
            if (a[x][y])
                return false;
        }

        for (int x = i, y = j; x >= 0 and y < n; x--, y++)
        {
            if (a[x][y])
                return false;
        }

        return true;
    }

    int solve(vector<vector<int>> &a, int row)
    {
        int n = a.size();
        if (row == n)
            return 1;

        int ans = 0;
        for (int j = 0; j < n; j++)
        {
            if (check(a, row, j))
            {
                a[row][j] = 1;
                ans += solve(a, row + 1);
                a[row][j] = 0;
            }
        }

        return ans;
    }

public:
    int totalNQueens(int n)
    {
        vector<vector<int>> a(n, vector<int>(n, 0));
        return solve(a, 0);
    }
};

int main()
{

    return 0;
}