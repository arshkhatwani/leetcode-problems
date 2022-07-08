#include <bits/stdc++.h>
using namespace std;

/*
We would observe that the traversal happens in the line connected by 4 corners and after each boundary completion all 4 corners shrink and we need to traverse and add elements to our answer till our element count < m*n where m,n are the dimensions of the given matrix

Watch video to understand more https://youtu.be/BJnMZNwUk1M
*/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &a)
    {
        int m = a.size(), n = a[0].size(), count = 0;
        vector<int> lTop = {0, 0}, lBottom = {m - 1, 0}, rTop = {0, n - 1}, rBottom = {m - 1, n - 1};
        vector<int> ans;

        while (count < m * n)
        {

            for (int j = lTop[1]; j <= rTop[1] and count < m * n; j++)
            {
                ans.push_back(a[lTop[0]][j]);
                count++;
            }

            for (int i = rTop[0] + 1; i <= rBottom[0] and count < m * n; i++)
            {
                ans.push_back(a[i][rTop[1]]);
                count++;
            }

            for (int j = rBottom[1] - 1; j >= lBottom[1] and count < m * n; j--)
            {
                ans.push_back(a[rBottom[0]][j]);
                count++;
            }

            for (int i = lBottom[0] - 1; i >= lTop[0] + 1 and count < m * n; i--)
            {
                ans.push_back(a[i][lBottom[1]]);
                count++;
            }

            lTop[0]++, lTop[1]++;
            rTop[0]++, rTop[1]--;
            lBottom[0]--, lBottom[1]++;
            rBottom[0]--, rBottom[1]--;
        }

        return ans;
    }
};

int main()
{

    return 0;
}