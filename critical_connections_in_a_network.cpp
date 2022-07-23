#include <bits/stdc++.h>
using namespace std;

/*
Just find the bridges / cut edges in a graph and add it to the answer array
*/

class Solution
{
    vector<vector<int>> ans;

    void dfs(int src, int parent, vector<vector<int>> &a, vector<int> &vis, vector<int> &low, vector<int> &tin, int &time)
    {
        vis[src] = 1;
        low[src] = tin[src] = time++;

        for (auto it : a[src])
        {
            if (it == parent)
                continue;

            if (!vis[it])
            {
                dfs(it, src, a, vis, low, tin, time);

                low[src] = min(low[src], low[it]);

                if (low[it] > tin[src])
                {
                    ans.push_back({src, it});
                }
            }
            else
            {
                low[src] = min(low[src], tin[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> a(n);
        ans.clear();

        for (auto i : connections)
        {
            a[i[0]].push_back(i[1]);
            a[i[1]].push_back(i[0]);
        }

        vector<int> vis(n, 0), low(n, 0), tin(n, 0);
        int time = 1;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                dfs(i, -1, a, vis, low, tin, time);
        }

        return ans;
    }
};

int main()
{

    return 0;
}