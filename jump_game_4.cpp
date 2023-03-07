#include <bits/stdc++.h>
using namespace std;

/*
Here to jump on next element we are using BFS

We are using an unordered map to store the indices for same values

TO SAVE TIME: we are clearing the index array associated with the value (in the map) after iterating it completely so that we do not need to iterate that particular index array again as the whole array is already visited/processed

Time Complexity: O(n)
Space Complexity: O(n)

See the code to understand in detail
*/

class Solution
{
public:
    int minJumps(vector<int> &a)
    {
        int n = a.size(), count = 0;
        unordered_map<int, vector<int>> mp;
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++)
        {
            mp[a[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int idx = q.front();
                q.pop();

                if (idx == n - 1)
                    return count;

                if (idx < n - 1 and !vis[idx + 1])
                {
                    vis[idx + 1] = 1;
                    q.push(idx + 1);
                }
                if (idx > 0 and !vis[idx - 1])
                {
                    vis[idx - 1] = 1;
                    q.push(idx - 1);
                }

                for (auto k : mp[a[idx]])
                {
                    if (!vis[k])
                    {
                        vis[k] = 1;
                        q.push(k);
                    }
                }
                mp[a[idx]].clear(); // performing this step to save time
            }
            count++;
        }

        return count;
    }
};

int main()
{

    return 0;
}