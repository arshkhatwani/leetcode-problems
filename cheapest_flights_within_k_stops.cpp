#include <bits/stdc++.h>
using namespace std;

/*
BFS Method
We have to do BFS from src node till k stops

Whenever we encounter node == dst we would calculate ans with the cost at that time

To keep the track of various costs along with the nodes we would keep the costs also with nodes in our visitation queue(queue used in BFS)

And to implement this 'k stops' kind of BFS we need to traverse the queue in the 'Level Order Traversal' way => like we would keep an outer while loop and inside we would run a for loop till the queue's current size and at when the for loop is over we decrement our 'k'(stops)
Something like this:

while(k and !q.empty()){
    for(int i = 0; i < q.size(); i++){
        // BFS operations
    }
    k--
}
we are gonna use k+1 instead of k in while loop because for example, if k = 1 => only 1 stop allowed, the while loop should be run 2 times here but it would only run one time as after one iteration k would be 0 and loop will terminate. So inorder to avoid that we would use k+ in the condition that's all.

Then we would also keep a costs array which would keep a track of minimum cost covered till a particular time
With the help of costs array we would only visit nodes if one of the below 2 conditions would be satisfied:
1. If node is unvisited i.e costs[node] == 0
2. If node is visited and the current cost is less than prev recorded cost of that node i.e costs[node] >= curCost + nodeCost

Then only we would push the node in the visitation queue. We are doing this to reduce time complexity

See the below code to understand this explanation
*/

class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> a(n);

        for (auto i : flights)
        {
            int u = i[0], v = i[1], w = i[2];

            a[u].push_back({w, v});
        }

        int ans = INT_MAX;
        vector<int> costs(n, 0);
        queue<pair<int, int>> q;
        q.push({src, 0});

        while (k + 1 and !q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                int node = q.front().first, curCost = q.front().second;
                q.pop();

                for (auto i : a[node])
                {
                    int neighborNode = i.second, cost = i.first;

                    if (neighborNode == dst)
                    {
                        ans = min(ans, curCost + cost);
                    }

                    else if (!costs[neighborNode] or costs[neighborNode] >= curCost + cost)
                    {
                        costs[neighborNode] = curCost + cost;
                        q.push({neighborNode, curCost + cost});
                    }
                }
            }
            k--;
        }

        ans = ans == INT_MAX ? -1 : ans;

        return ans;
    }
};

int main()
{

    return 0;
}