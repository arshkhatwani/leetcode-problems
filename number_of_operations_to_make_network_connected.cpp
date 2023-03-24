#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> size, parent;
    DisjointSet(int n)
    {
        size.resize(n, 1);
        parent.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findUPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v)
    {
        int parU = findUPar(u), parV = findUPar(v);
        if (parU == parV)
            return;
        if (size[parU] > size[parV])
        {
            parent[parV] = parU;
        }
        else
        {
            parent[parU] = parV;
        }
    }
};

/*
The idea is to calculate connected components(ultimate parents: parents which are parents of themselves), then the number of edges needed to make the graph connected will be connected components - 1

The number of extra edges (edges which can be removed without breaking the connection) will be those when the nodes connected via them are already belonging to same parent

If the extra edges are less than edges needed then we can return -1 else we return edges needed

See the code to understand in detail
*/

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        int connectedComp = 0, extraEdges = 0, edgesNeeded = 0;
        DisjointSet dsu(n);

        for (auto c : connections)
        {
            int u = c[0], v = c[1];
            if (dsu.findUPar(u) == dsu.findUPar(v))
                extraEdges++;
            dsu.unionBySize(u, v);
        }

        for (int i = 0; i < n; i++)
        {
            if (dsu.findUPar(i) == i)
                connectedComp++;
        }
        edgesNeeded = connectedComp - 1;

        if (edgesNeeded > extraEdges)
            return -1;
        return edgesNeeded;
    }
};

int main()
{

    return 0;
}