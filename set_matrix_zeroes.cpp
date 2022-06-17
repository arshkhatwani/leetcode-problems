#include <bits/stdc++.h>
using namespace std;

/*
The brute solution would be to take another matrix and set zeroes according to the original one and then replace it with original matrix, and there's your answer
TC : O(m x n)
SC : O(m x n)

The better solution would be to take a row array and col array and update them once we encounter any 0 in the first traversal
In second traversal, we can replace the 0s in original matrix if any of the row or col array contains a 0 at that index
TC : 2 x O(m x n)
SC : O(m + n)

The most optimal solution would be to treat the first row and column of the matrix as the row and col array like in previous approach and we would iterate from second column (i.e j = 1) and to check if the first column has zero or not we will keep a boolean flag

So during our first traversal if we will encounter a 0 we will modify the 1st row, col and set them to 0
Now everytime we come to a new row we will check that if an element in the first col of that row is 0 or not, if yes then we will set our boolean to false, as we now know that whole column would now become 0 due to that

So now in second traversal we will traverse from back till 2nd col like above traversal we can replace the 0s in original matrix if the 1st row/col contains a 0 at that index, and everytime we come in a new row, we will check if flag is true or false, if (false) then we will set the element to 0 present at first column of that row
TC: 2 x O(m x n)
SC: O(1)
*/

class Solution
{
public:
    void setZeroes(vector<vector<int>> &a)
    {
        int m = a.size(), n = a[0].size();
        bool col = true;

        for (int i = 0; i < m; i++)
        {
            if (a[i][0] == 0)
                col = false;
            for (int j = 1; j < n; j++)
            {
                if (a[i][j] == 0)
                {
                    a[i][0] = 0;
                    a[0][j] = 0;
                }
            }
        }

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 1; j--)
            {
                if (a[i][0] == 0 or a[0][j] == 0)
                    a[i][j] = 0;
            }

            if (!col)
                a[i][0] = 0;
        }
    }
};

int main()
{

    return 0;
}