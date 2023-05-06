#include <bits/stdc++.h>
using namespace std;

// This question can be solved using DSU

class DisjointSet
{
public:
    vector<int> parent, size;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
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
            size[parU] += size[parV];
        }
        else
        {
            parent[parU] = parV;
            size[parV] += size[parU];
        }
    }
};

class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        DisjointSet ds1(n), ds2(n);
        int cuts = 0;

        for (auto e : edges)
        {
            int t = e[0], u = e[1], v = e[2];

            if (t != 3)
                continue;
            if (ds1.findUPar(u) == ds1.findUPar(v) or ds2.findUPar(u) == ds2.findUPar(v))
                cuts++;

            ds1.unionBySize(u, v);
            ds2.unionBySize(u, v);
        }

        for (auto e : edges)
        {
            int t = e[0], u = e[1], v = e[2];

            if (t == 1)
            {
                if (ds1.findUPar(u) == ds1.findUPar(v))
                    cuts++;
                ds1.unionBySize(u, v);
            }
            else if (t == 2)
            {
                if (ds2.findUPar(u) == ds2.findUPar(v))
                    cuts++;
                ds2.unionBySize(u, v);
            }
        }

        int par1 = ds1.findUPar(1), par2 = ds2.findUPar(1);
        for (int i = 1; i <= n; i++)
        {
            if (ds1.findUPar(i) != par1 or ds2.findUPar(i) != par2)
                return -1;
        }

        return cuts;
    }
};

int main()
{

    return 0;
}