#include <bits/stdc++.h>
using namespace std;

/*
Logic: https://leetcode.com/problems/minimum-number-of-flips-to-convert-binary-matrix-to-zero-matrix/discuss/446712/C%2B%2B-easy-recursive-solution.
*/

class Solution
{
    vector<vector<int>> flipMat(vector<vector<int>> a, int i, int j)
    {
        int m = a.size(), n = a[0].size();

        a[i][j] ^= 1;

        if (i > 0)
            a[i - 1][j] ^= 1;
        if (i < m - 1)
            a[i + 1][j] ^= 1;
        if (j > 0)
            a[i][j - 1] ^= 1;
        if (j < n - 1)
            a[i][j + 1] ^= 1;

        return a;
    }

    bool isZeroMat(vector<vector<int>> &a)
    {
        int m = a.size(), n = a[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j])
                    return false;
            }
        }

        return true;
    }

    int solve(vector<vector<int>> &a, int i, int j)
    {
        int m = a.size(), n = a[0].size();
        if (j == n)
        {
            i++;
            j = 0;
        }
        if (i == m)
        {
            if (isZeroMat(a))
                return 0;
            return 1e9;
        }

        vector<vector<int>> newMat = flipMat(a, i, j);

        int flip = 1 + solve(newMat, i, j + 1);
        int notFlip = solve(a, i, j + 1);

        return min(flip, notFlip);
    }

public:
    int minFlips(vector<vector<int>> &mat)
    {
        int ans = solve(mat, 0, 0);

        if (ans >= 1e9)
            return -1;

        return ans;
    }
};

int main()
{

    return 0;
}