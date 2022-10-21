#include <bits/stdc++.h>
using namespace std;

/*
First work on rows of the matrix, calculate the original number formed by the rows and the flipped number. If flipped num > orignal num then flip that row

Now work on coilumns of the matrix. For each column see count 0s and 1s if count of 0s > count of 1s then flip the column

Calculate the sum of numbers formed by the rows and return it as answer
*/

class Solution
{
public:
    int matrixScore(vector<vector<int>> &a)
    {
        int m = a.size(), n = a[0].size();

        for (int i = 0; i < m; i++)
        {
            int orignal = 0, flipped = 0;

            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 1)
                {
                    orignal |= (1 << (n - 1 - j));
                }
                else
                {
                    flipped |= (1 << (n - 1 - j));
                }
            }

            if (orignal < flipped)
            {
                for (int j = 0; j < n; j++)
                {
                    a[i][j] ^= 1;
                }
            }
        }

        for (int j = 0; j < n; j++)
        {
            int count0s = 0, count1s = 0;

            for (int i = 0; i < m; i++)
            {
                count0s += (a[i][j] == 0);
                count1s += (a[i][j] == 1);
            }

            if (count0s > count1s)
            {
                for (int i = 0; i < m; i++)
                {
                    a[i][j] ^= 1;
                }
            }
        }

        int sum = 0;

        for (int i = 0; i < m; i++)
        {
            int rowNum = 0;
            for (int j = 0; j < n; j++)
            {
                rowNum |= (a[i][j] << (n - 1 - j));
            }
            sum += rowNum;
        }

        return sum;
    }
};

int main()
{

    return 0;
}