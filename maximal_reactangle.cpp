#include <bits/stdc++.h>
using namespace std;

/*
We will take an empty array (say heights) of row's size and keep adding the rows every time we move down the column

If there would be 1 in the current iteration row then we'll add it else we will set the index value to 0 in the heights array no matter what the previous value was in the previous iterations

In every iteration to find the largest area of rectangle(monotonic stack) in the heights array and keep track of the maximum throughout the iterations

The maximum will be our answer
Video: https://youtu.be/tOylVCugy9k
*/

class Solution
{
    int largestRectangleArea(vector<int> &a)
    {
        stack<int> st;
        int n = a.size(), maxArea = 0;

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() and (i == n or a[st.top()] >= a[i]))
            {
                int height = a[st.top()];
                st.pop();

                int rs = i, ls = !st.empty() ? st.top() : -1;
                int width = rs - ls - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }

public:
    int maximalRectangle(vector<vector<char>> &a)
    {
        int m = a.size(), n = a[0].size();
        vector<int> heights(n, 0);
        int area = 0, maxArea = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }

            area = largestRectangleArea(heights);
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};

int main()
{

    return 0;
}