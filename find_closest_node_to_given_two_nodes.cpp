#include <bits/stdc++.h>
using namespace std;

/*
The idea is to calculate shortest path to all nodes from node1 and node2 separately

Then for every node we would calculate the maximum of both paths and keep an ans variable which would store the index of the node and a variable which would store the minimum of maximum of paths between a node and both node1 and node2

That ans variable would be our answer
See the code to understand more
*/

// Optimised
class Solution
{
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<int> path1(n, 1e9), path2(n, 1e9);

        for (int i = node1, dist = 0; i != -1 and path1[i] == 1e9; i = edges[i])
        {
            path1[i] = dist++;
        }

        for (int i = node2, dist = 0; i != -1 and path2[i] == 1e9; i = edges[i])
        {
            path2[i] = dist++;
        }

        int ans = -1, maxAmongDistance = 1e9;
        for (int i = 0; i < n; i++)
        {
            if (maxAmongDistance > max(path1[i], path2[i]))
            {
                maxAmongDistance = max(path1[i], path2[i]);
                ans = i;
            }
        }

        return ans;
    }
};

// Plain DFS
class Solution
{
    void dfs(int src, vector<vector<int>> &a, vector<int> &path)
    {
        for (auto node : a[src])
        {
            if (path[node] > path[src] + 1)
            {
                path[node] = path[src] + 1;
                dfs(node, a, path);
            }
        }
    }

public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2)
    {
        int n = edges.size();
        vector<vector<int>> a(n);

        for (int i = 0; i < n; i++)
        {
            if (edges[i] == -1)
                continue;

            a[i].push_back(edges[i]);
        }

        vector<int> path1(n, 1e9), path2(n, 1e9);
        path1[node1] = 0, path2[node2] = 0;

        dfs(node1, a, path1);
        dfs(node2, a, path2);

        int ans = -1, maxAmongDistance = 1e9;
        for (int i = 0; i < n; i++)
        {
            if (maxAmongDistance > max(path1[i], path2[i]))
            {
                maxAmongDistance = max(path1[i], path2[i]);
                ans = i;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}