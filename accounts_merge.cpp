#include <bits/stdc++.h>
using namespace std;

/*
Video link https://youtu.be/FMwpt_aQOGw
*/

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        parent.resize(n, 0);
        size.resize(n, 1);
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
        if (size[parU] < size[parV])
        {
            parent[parU] = parV;
            size[parV] += size[parU];
        }
        else
        {
            parent[parV] = parU;
            size[parU] += size[parV];
        }
    }
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        int n = accounts.size();
        DisjointSet dsu(n);
        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < accounts[i].size(); j++)
            {
                if (mp.find(accounts[i][j]) == mp.end())
                {
                    mp[accounts[i][j]] = i;
                }
                else
                {
                    dsu.unionBySize(mp[accounts[i][j]], i);
                }
            }
        }

        vector<vector<string>> a(n);
        for (auto i : mp)
        {
            string mail = i.first;
            int idx = dsu.findUPar(i.second);
            a[idx].push_back(mail);
        }
        vector<vector<string>> ans;
        for (int i = 0; i < n; i++)
        {
            if (a[i].size() == 0)
                continue;

            sort(a[i].begin(), a[i].end());
            vector<string> nameNMail = {accounts[i][0]};
            for (auto k : a[i])
                nameNMail.push_back(k);

            ans.push_back(nameNMail);
        }

        return ans;
    }
};

int main()
{

    return 0;
}