#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Take a hashmap and store all the parents of all nodes
Find the node of infected value
Do BFS / Level order traversal from that node and keep a visited/infected map which tells whether a node is infected or not. Keep doing BFS till all the nodes are infected
During BFS keep a track of time (see code to understand) and return it in the end
*/

class Solution
{
    unordered_map<TreeNode *, TreeNode *> parents;
    int time;
    unordered_map<TreeNode *, bool> infected;

    void setParents(TreeNode *root)
    {
        if (!root)
            return;

        if (root->left)
            parents[root->left] = root;
        if (root->right)
            parents[root->right] = root;

        setParents(root->left);
        setParents(root->right);
    }

    TreeNode *findInfected(TreeNode *root, int start)
    {
        TreeNode *node = NULL;

        if (root->val == start)
            return root;

        for (auto i : parents)
        {
            if (i.first->val == start)
            {
                node = i.first;
                break;
            }

            if (i.second->val == start)
            {
                node = i.second;
                break;
            }
        }

        return node;
    }

public:
    int amountOfTime(TreeNode *root, int start)
    {
        parents.clear();
        setParents(root);

        TreeNode *infectedNode = findInfected(root, start);

        queue<TreeNode *> q;
        q.push(infectedNode);
        infected[infectedNode] = true;

        int t = -1; // because at 0 minutes only node with 'start' value is infected and at 1 minute all the neighbours of start would be infected
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (parents.find(node) != parents.end() and !infected[parents[node]])
                {
                    infected[parents[node]] = true;
                    q.push(parents[node]);
                }
                if (node->left and !infected[node->left])
                {
                    infected[node->left] = true;
                    q.push(node->left);
                }
                if (node->right and !infected[node->right])
                {
                    infected[node->right] = true;
                    q.push(node->right);
                }
            }
            t++;
        }

        return t;
    }
};

int main()
{

    return 0;
}