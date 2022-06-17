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
https://leetcode.com/problems/house-robber-iii/discuss/1782113/C%2B%2B-or-Recursion-and-Memoization

For every node "root", we have two choices:

    Take the root value and directly traverse to the neighbours of the nodes which are neighbours of root.
    Don't take the root value and traverse to the neightbours of root.

The maximum of these two choices will be our answer.
Since there will be overlapping subproblems, we are memoizing our recursion.
*/

int solve(TreeNode *root, unordered_map<TreeNode *, int> &dp)
{
    if (!root)
        return 0;
    if (!root->left and !root->right)
    {
        return root->val;
    }

    if (dp[root] != 0)
        return dp[root];

    int choice1 = root->val;
    if (root->left)
        choice1 += solve(root->left->left, dp) + solve(root->left->right, dp);
    if (root->right)
        choice1 += solve(root->right->left, dp) + solve(root->right->right, dp);

    int choice2 = solve(root->left, dp) + solve(root->right, dp);

    return dp[root] = max(choice1, choice2);
}
int rob(TreeNode *root)
{
    unordered_map<TreeNode *, int> dp;
    return solve(root, dp);
}

int main()
{

    return 0;
}