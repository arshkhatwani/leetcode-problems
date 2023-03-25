#include <bits/stdc++.h>
using namespace std;

// Video: https://youtu.be/m17yOR5_PpI

class Solution
{
    int count;
    void dfs(int src, vector<vector<pair<int, int>>> &a, vector<int> &vis)
    {
        vis[src] = 1;

        for (auto i : a[src])
        {
            int node = i.first;
            if (vis[node])
                continue;

            count += i.second;
            dfs(node, a, vis);
        }
    }

public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<pair<int, int>>> a(n);

        for (auto c : connections)
        {
            int u = c[0], v = c[1];
            a[u].push_back({v, 1});
            a[v].push_back({u, 0});
        }

        count = 0;
        vector<int> vis(n, 0);

        dfs(0, a, vis);

        return count;
    }
};

int main()
{

    return 0;
}