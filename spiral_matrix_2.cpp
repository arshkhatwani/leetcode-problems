#include <bits/stdc++.h>
using namespace std;

/*
Logic: https://youtu.be/yeGAAUzAPnU
*/

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int r1 = 0, r2 = n - 1, c1 = 0, c2 = n - 1;
        int val = 1;

        while (r1 <= r2 and c1 <= c2)
        {
            for (int c = c1; c <= c2; c++)
                ans[r1][c] = val++;

            for (int r = r1 + 1; r <= r2; r++)
                ans[r][c2] = val++;

            if (c1 < c2 and r1 < r2)
            {
                for (int c = c2 - 1; c > c1; c--)
                    ans[r2][c] = val++;

                for (int r = r2; r > r1; r--)
                    ans[r][c1] = val++;
            }

            r1++, c1++;
            r2--, c2--;
        }

        return ans;
    }
};

int main()
{

    return 0;
}