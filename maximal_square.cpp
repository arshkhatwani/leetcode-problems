#include <bits/stdc++.h>
using namespace std;

/*
DP:
Video: https://youtu.be/auS1fynpnjo

Stack:
We can use the maximal rectangle logic here with a slight change in the area calculation logic
*/

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &a)
    {
        int m = a.size();
        int n = a[m - 1].size();
        int maxLen = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == m - 1 or j == n - 1)
                {
                    if (a[i][j] == '1')
                        dp[i][j] = 1;
                }
                else
                {
                    if (a[i][j] == '1')
                        dp[i][j] = min(dp[i + 1][j], min(dp[i + 1][j + 1], dp[i][j + 1])) + 1;
                }
                maxLen = max(maxLen, dp[i][j]);
            }
        }

        return maxLen * maxLen;
    }
};

class Solution
{
    int largestArea(vector<int> &a)
    {
        int n = a.size(), area = 0, maxArea = 0;
        stack<int> st;

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() and (i == n or a[st.top()] >= a[i]))
            {
                int height = a[st.top()];
                st.pop();

                int width = st.empty() ? i : i - st.top() - 1;

                area = min(width, height) * min(width, height); // this would give us only the area of square
                maxArea = max(area, maxArea);
            }
            st.push(i);
        }

        return maxArea;
    }

public:
    int maximalSquare(vector<vector<char>> &a)
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

            area = largestArea(heights);
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};

int main()
{

    return 0;
}