#include <bits/stdc++.h>
using namespace std;

/*  My algorithm
We can rotate matrix clockwise by 1 point, so now we need to use this function different times for different rings/layers
in even numbered matrix, say 4x4 we will need to rotate the most outer ring 3 times then as we go in we will encounter 2x2 ring and we will rotate it 1 times (i.e start the number of rotations by (n-1) (n=size of matrix) and decrement the number of rotations by 2 every time we go to an inner ring)
in odd numbered matrix, say 5x5 we will need to rotate the most outer ring 4 times then as we go in we will encounter 3x3 ring and we will rotate it 2 times, then 1x1 ring which we will rotate 0 times (i.e start the number of rotations by (n-1) (n=size of matrix) and decrement the number of rotations by 2 every time we go to an inner ring)
*/

// class Solution
// {
// private:
//     void rotate2(vector<vector<int>> &a, int k, int t)
//     {
//         int n = a.size();
//         while (t--)
//         {
//             int newVar = a[k][k];

//             for (int i = k + 1; i <= n - 1 - k; i++)
//             {
//                 a[i - 1][k] = a[i][k];
//             }

//             for (int j = k + 1; j <= n - 1 - k; j++)
//             {
//                 a[n - 1 - k][j - 1] = a[n - 1 - k][j];
//             }

//             for (int i = n - 2 - k; i >= k; i--)
//             {
//                 a[i + 1][n - k - 1] = a[i][n - k - 1];
//             }

//             for (int j = n - 2 - k; j >= k; j--)
//             {
//                 a[k][j + 1] = a[k][j];
//             }
//             a[k][k + 1] = newVar;
//         }
//     }

// public:
//     void rotate(vector<vector<int>> &a)
//     {
//         int n = a.size();

//         for (int i = 0, t = n - 1; i < n / 2; i++, t = t - 2)
//         {
//             rotate2(a, i, t);
//         }
//     }
// };

// Striver's algo
// Get the transpose of a matrix and reverse the rows
class Solution
{
public:
    void rotate(vector<vector<int>> &a)
    {
        int n = a.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(a[i][j], a[j][i]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            reverse(a[i].begin(), a[i].end());
        }
    }
};

int main()
{

    return 0;
}