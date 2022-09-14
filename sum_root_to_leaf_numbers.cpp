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
    int ans = 0;

    void dfs(TreeNode *root, int sum)
    {
        if (!root)
            return;
        if (!root->left and !root->right)
        {
            ans += sum * 10 + root->val;
            return;
        }

        dfs(root->left, sum * 10 + root->val);
        dfs(root->right, sum * 10 + root->val);
    }

public:
    int sumNumbers(TreeNode *root)
    {
        dfs(root, 0);
        return ans;
    }
};

int main()
{

    return 0;
}