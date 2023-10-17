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

class Solution
{
    bool solve(TreeNode *root, TreeNode *min, TreeNode *max)
    {
        if (!root)
            return true;

        if ((min and root->val <= min->val) or (max and root->val >= max->val))
            return false;

        bool left = solve(root->left, min, root);
        bool right = solve(root->right, root, max);

        return left and right;
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return solve(root, NULL, NULL);
    }
};

int main()
{

    return 0;
}