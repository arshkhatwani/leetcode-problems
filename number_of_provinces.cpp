#include <bits/stdc++.h>
using namespace std;

/*
You just need to count the number of connected components in a graph

Another Approach:
This problem can also be solved using DSU. And the ultimate parents can be counted after all the unions
Any node which is parent of itself is the ultimate parent
*/

// DSU
class Solution
{
    vector<int> rank, parent;
    int findPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }
    void unionByRank(int a, int b)
    {
        int parentA = findPar(a);
        int parentB = findPar(b);

        if (parentA == parentB)
            return;

        if (rank[parentA] > rank[parentB])
        {
            parent[parentB] = parentA;
        }
        else if (rank[parentA] < rank[parentB])
        {
            parent[parentA] = parentB;
        }
        else
        {
            parent[parentA] = parentB;
            rank[parentB]++;
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            rank[i] = 0;
            parent[i] = i;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j])
                {
                    unionByRank(i, j);
                }
            }
        }

        int totalParents = 0;
        for (int i = 0; i < n; i++)
        {
            if (findPar(i) == i)
                totalParents++;
        }

        return totalParents;
    }
};

// Graph
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