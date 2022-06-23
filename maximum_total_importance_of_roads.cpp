#include <bits/stdc++.h>
using namespace std;

/*
For the maximum result, we assign the highest value to a city with the largest degree (number of roads).

We compute the degree of each node, and then sort them. Finally, we assing increasing values starting from the smallest degree.
*/

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<int> degree(n, 0);

        for (auto i : roads)
        {
            int u = i[0], v = i[1];

            degree[u]++;
            degree[v]++;
        }

        sort(degree.begin(), degree.end());

        long long ans = 0, num = 1;
        for (auto i : degree)
        {
            ans += num * i;
            num++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}