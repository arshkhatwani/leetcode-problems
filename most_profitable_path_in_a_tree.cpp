#include <bits/stdc++.h>
using namespace std;

/*
We can first calculate bob's path as there is only one path for bob

We will keep a visited array that will keep track of the time at which bob visited nodes

Then we will calculate alice's path and for every node alice visits we check if bob visited that node or not
    If bob has not visited that node then we will add amount[node] to answer
    if bob has visited and time is greater than visiting time of alice then we will add amount[node] to answer
    If bob has visited and time is equal to visiting time of alice then we will add amount[node]/2 to answer

We will maximise alice's answer and return it
*/

class Solution
{
    int dfsBob(int src, vector<vector<int>> &a, vector<int> &vis, int idx)
    {
        vis[src] = idx;
        if (src == 0)
            return 1;
        for (auto node : a[src])
        {
            if (vis[node] != -1)
                continue;
            if (dfsBob(node, a, vis, idx + 1))
                return 1;
        }
        vis[src] = -1;
        return 0;
    }

    int dfsAlice(int src, vector<vector<int>> &a, vector<int> &vis, int idx, vector<int> &amount, vector<int> &visBob)
    {
        bool isLeaf = true;
        vis[src] = 1;

        int ans = INT_MIN;
        for (auto node : a[src])
        {
            if (vis[node])
                continue;

            isLeaf = false;
            int subAns = dfsAlice(node, a, vis, idx + 1, amount, visBob);

            if (visBob[node] != -1 and visBob[node] < idx + 1)
                subAns += 0;
            else if (visBob[node] == idx + 1)
                subAns += amount[node] / 2;
            else
                subAns += amount[node];

            ans = max(ans, subAns);
        }

        if (ans == INT_MIN)
            ans = 0;

        return ans;
    }

public:
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
    {
        int n = edges.size() + 1;
        vector<vector<int>> a(n);

        for (auto i : edges)
        {
            int u = i[0], v = i[1];
            a[u].push_back(v);
            a[v].push_back(u);
        }
        vector<int> visBob(n, -1);
        vector<int> visAlice(n, 0);

        dfsBob(bob, a, visBob, 0);
        int ans = dfsAlice(0, a, visAlice, 0, amount, visBob) + amount[0];

        return ans;
    }
};

int main()
{

    return 0;
}