#include <bits/stdc++.h>
using namespace std;

/*
You just need to count the number of connected components in a graph
*/

class Solution
{
public:
    void dfs(int src, vector<vector<int>> &a, vector<int> &visited)
    {
        if (visited[src] == 1)
            return;
        visited[src] = 1;
        for (int i = 0; i < a[src].size(); i++)
        {
            if (a[src][i] == 1)
            {
                if (visited[i] == 0)
                {
                    dfs(i, a, visited);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>> &a)
    {
        int n = a.size();
        vector<int> visited(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                ans += 1;
                dfs(i, a, visited);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}