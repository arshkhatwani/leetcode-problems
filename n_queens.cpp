#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<string> a;
    vector<vector<string>> ans;

    bool isSafe(int x, int y)
    {
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            if (a[x][i] == 'Q')
                return false;
            else if (a[i][y] == 'Q')
                return false;
        }

        for (int i = x, j = y; i < n and j < n; i++, j++)
        {
            if (a[i][j] == 'Q')
                return false;
        }

        for (int i = x, j = y; i >= 0 and j >= 0; i--, j--)
        {
            if (a[i][j] == 'Q')
                return false;
        }

        for (int i = x, j = y; i < n and j >= 0; i++, j--)
        {
            if (a[i][j] == 'Q')
                return false;
        }

        for (int i = x, j = y; i >= 0 and j < n; i--, j++)
        {
            if (a[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int row, int &total)
    {
        int n = a.size();

        if (row == n)
            return;

        for (int i = 0; i < n; i++)
        {
            if (isSafe(row, i))
            {
                a[row][i] = 'Q';
                total++;

                solve(row + 1, total);

                if (total == n)
                {
                    ans.push_back(a);
                }

                total--;
                a[row][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        ans.clear();
        a = vector<string>(n, string(n, '.'));
        int total = 0;
        solve(0, total);

        return ans;
    }
};

int main()
{

    return 0;
}