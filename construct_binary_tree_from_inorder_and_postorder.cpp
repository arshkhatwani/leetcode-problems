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

// Video https://youtu.be/LgLRTaEMRVc

class Solution
{
    TreeNode *build(unordered_map<int, int> &mp, vector<int> &postorder, int is, int ie, int ps, int pe)
    {
        if (is > ie)
            return NULL;

        int node = postorder[pe];
        int inorderIdx = mp[node];
        TreeNode *root = new TreeNode(node);

        int nodesLeft = inorderIdx - is;
        int nodesRight = ie - inorderIdx;

        root->left = build(mp, postorder, is, inorderIdx - 1, ps, ps + nodesLeft - 1);
        root->right = build(mp, postorder, inorderIdx + 1, ie, ps + nodesLeft, ps + nodesLeft + nodesRight - 1);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }

        return build(mp, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};

int main()
{

    return 0;
}