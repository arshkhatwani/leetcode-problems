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
For every tree/subtree we are creating its tree in form of string and using a map to keep track of the duplicate
Refer to understand in detail: https://youtu.be/kn0Z5_qPPzY
*/

class Solution
{
    unordered_map<string, vector<TreeNode *>> mp;
    string preorder(TreeNode *root)
    {
        if (!root)
        {
            return "null";
        }

        string tree = to_string(root->val) + ',';
        string leftTree = preorder(root->left);
        string rightTree = preorder(root->right);
        tree += leftTree;
        tree += ',';
        tree += rightTree;

        mp[tree].push_back(root);

        return tree;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        mp.clear();
        preorder(root);
        vector<TreeNode *> ans;

        for (auto i : mp)
        {
            if (i.second.size() > 1)
            {
                TreeNode *node = i.second[0];
                ans.push_back(node);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}