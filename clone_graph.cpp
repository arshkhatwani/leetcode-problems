#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

/*
We can store (old, new) nodes pairwise in a hashmap
We can traverse the given graph using DFS and keep a hashmap to keep track of visited nodes

Now if a node is not visited that means its deep copy node has not been made yet. So we call DFS for that node

And if a node is already visited that means its copy has been made and we nust need to add that already made copy to the neighbors array of current dfs's src node's copy

See the code to understand more
*/

// solution 1
class Solution
{
    unordered_map<Node *, int> visited;
    unordered_map<Node *, Node *> oldNew;

    void dfs(Node *src, Node *newNode)
    {
        visited[src] = 1;
        oldNew[src] = newNode;

        for (Node *node : src->neighbors)
        {
            if (!visited[node])
            {
                Node *newCopyNode = new Node(node->val);
                dfs(node, newCopyNode);
            }
            newNode->neighbors.push_back(oldNew[node]);
        }
    }

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return node;

        Node *newNode = new Node(node->val);

        dfs(node, newNode);

        return newNode;
    }
};

// solution 2 (same logic slight different implementation)
class Solution
{
    unordered_map<Node *, int> visited;
    unordered_map<Node *, Node *> oldNew;

    Node *dfs(Node *src)
    {
        visited[src] = 1;

        Node *newNode = new Node(src->val);
        oldNew[src] = newNode;

        for (Node *node : src->neighbors)
        {
            if (!visited[node])
            {
                dfs(node);
            }
            newNode->neighbors.push_back(oldNew[node]);
        }

        return newNode;
    }

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return node;
        return dfs(node);
    }
};

int main()
{

    return 0;
}