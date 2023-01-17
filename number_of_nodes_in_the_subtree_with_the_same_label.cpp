#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<int> dfs(int src, vector<vector<int>> &a, string &labels, vector<int> &ans, vector<int> &visited)
    {
        vector<int> chars(26, 0);
        chars[labels[src] - 'a'] += 1;

        for (auto node : a[src])
        {
            if (visited[node])
                continue;

            visited[node] = 1;
            vector<int> newChars = dfs(node, a, labels, ans, visited);

            for (int i = 0; i < 26; i++)
            {
                chars[i] += newChars[i];
            }
        }
        ans[src] = chars[labels[src] - 'a'];

        return chars;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        vector<vector<int>> a(n);
        vector<int> ans(n, 0), visited(n, 0);

        for (auto e : edges)
        {
            int u = e[0], v = e[1];
            a[u].push_back(v);
            a[v].push_back(u);
        }

        visited[0] = 1;
        dfs(0, a, labels, ans, visited);

        return ans;
    }
};

int main()
{

    return 0;
}