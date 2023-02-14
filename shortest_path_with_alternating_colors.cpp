#include <bits/stdc++.h>
using namespace std;

/*
This problem can be solved using BFS with keeping track of edge and a 2d visited array which will store whether a node has been visited using a particular edge or not

See the code to understand in detail
*/

class Solution
{
    void bfs(int n, vector<vector<int>> &reds, vector<vector<int>> &blues, vector<int> &ans, char startColor)
    {
        int dis = 0;
        queue<pair<int, char>> q;
        q.push({0, startColor});

        vector<vector<int>> visited(n, vector<int>(2, 0));
        if (startColor == 'r')
            visited[0][1] = 1;
        else
            visited[0][0] = 1;

        while (!q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                int src = q.front().first;
                char color = q.front().second;
                q.pop();
                if (color == 'r')
                {
                    for (auto node : reds[src])
                    {
                        if (visited[node][0])
                            continue;
                        visited[node][0] = 1;
                        ans[node] = min(ans[node], dis + 1);
                        q.push({node, 'b'});
                    }
                }
                else
                {
                    for (auto node : blues[src])
                    {
                        if (visited[node][1])
                            continue;
                        visited[node][1] = 1;
                        ans[node] = min(ans[node], dis + 1);
                        q.push({node, 'r'});
                    }
                }
            }
            dis++;
        }
    }

public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<vector<int>> reds(n), blues(n);

        for (auto m : redEdges)
        {
            int u = m[0], v = m[1];
            reds[u].push_back(v);
        }
        for (auto m : blueEdges)
        {
            int u = m[0], v = m[1];
            blues[u].push_back(v);
        }

        vector<int> ans(n, INT_MAX);
        ans[0] = 0;

        bfs(n, reds, blues, ans, 'r');
        bfs(n, reds, blues, ans, 'b');

        for (int i = 1; i < n; i++)
        {
            ans[i] = ans[i] == INT_MAX ? -1 : ans[i];
        }

        return ans;
    }
};

int main()
{

    return 0;
}