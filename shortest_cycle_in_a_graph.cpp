#include <bits/stdc++.h>
using namespace std;

/*
If we do DFS / BFS from a node and keep track of distance of visited nodes and parents of those nodes

And once we encounter a node whose distance has already been recorded and the node is not parent of the source node then we know that there is a cycle

And the length of that cycle will be:
dis[node] (distance which was already recorded when the node was visited) + dis[source node] + 1 (common edge)

And we will keep track of minimum length encountered

Refer to understand more: https://leetcode.com/problems/shortest-cycle-in-a-graph/solutions/3366629/intuitive-approach-dfs-bfs-clean-code-c/
*/

class Solution
{
    void bfs(int src, vector<vector<int>> &a, int &minCycle)
    {
        int n = a.size();
        vector<int> dis(n, 1e9), parent(n, -1);

        queue<int> q;
        q.push(src);
        dis[src] = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto i : a[node])
            {
                if (dis[i] == 1e9)
                {
                    dis[i] = dis[node] + 1;
                    parent[i] = node;
                    q.push(i);
                }
                else if (parent[node] != i)
                {
                    minCycle = min(minCycle, dis[i] + dis[node] + 1);
                }
            }
        }
    }

public:
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> a(n);
        int minCycle = 1e9;

        for (auto e : edges)
        {
            int u = e[0], v = e[1];
            a[u].push_back(v);
            a[v].push_back(u);
        }

        for (int i = 0; i < n; i++)
        {
            bfs(i, a, minCycle);
        }

        if (minCycle == 1e9)
            return -1;
        return minCycle;
    }
};

int main()
{

    return 0;
}