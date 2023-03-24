#include <bits/stdc++.h>
using namespace std;

/*
First we need to travel (DFS, BFS) from city 1 to see what cities can be gone with city 1, this is done because if we go those cities then we can also come back

Then we iterate through all the roads and if any of the 2 cities(connecting through that road) is/are visitable by city 1 then we calculate a minimum value between that road and answer and then we return the minimum value calculated as answer

See the code to understand more
*/

class Solution
{
    void dfs(int src, vector<vector<int>> &a, vector<int> &vis)
    {
        if (vis[src])
            return;
        vis[src] = 1;

        for (auto node : a[src])
        {
            dfs(node, a, vis);
        }
    }

public:
    int minScore(int n, vector<vector<int>> &roads)
    {
        vector<vector<int>> a(n + 1);
        for (auto i : roads)
        {
            int u = i[0], v = i[1];
            a[u].push_back(v);
            a[v].push_back(u);
        }
        vector<int> vis(n + 1, 0);

        dfs(1, a, vis);

        int ans = INT_MAX;
        for (auto i : roads)
        {
            int u = i[0], v = i[1], d = i[2];
            if (!vis[u] and !vis[v])
                continue;

            ans = min(ans, d);
        }

        return ans;
    }
};

int main()
{

    return 0;
}