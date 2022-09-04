#include <bits/stdc++.h>
using namespace std;

/*
We will explore all ways of choosing columns
At every column we have a 2 options:
-> to choose it
-> to not choose it
We will keep a bitmask for tracking which column we have chosen and which we have not

BASE CASE:
After we are done choosing all the problems we will count the number of covered rows and return it

Since we want maximum rows to be covered we will return max(choose, notChoose)

Since constraints are low brute force recursion will work here
See the code to understand more
*/

class Solution
{
    int f(int n, vector<vector<int>> &a, int mask, int cols)
    {
        if (!n and cols)
            return 0;

        if ((!n and !cols) or !cols)
        {
            int m = a.size();
            int count = 0;
            n = a[0].size();

            for (int i = 0; i < m; i++)
            {
                int isCovered = 1;
                for (int j = 0; j < n; j++)
                {
                    int isPresent = mask & (1 << j);

                    if (a[i][j] == 1 and !isPresent)
                    {
                        isCovered = 0;
                        break;
                    }
                }
                count += isCovered;
            }

            return count;
        }

        int newMask = mask | (1 << (n - 1));

        int choose = f(n - 1, a, newMask, cols - 1);
        int notChoose = f(n - 1, a, mask, cols);

        return max(choose, notChoose);
    }

public:
    int maximumRows(vector<vector<int>> &mat, int cols)
    {
        int mask = 0;
        int n = mat[0].size();
        return f(n, mat, mask, cols);
    }
};

int main()
{

    return 0;
}