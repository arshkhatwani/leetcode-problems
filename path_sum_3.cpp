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

void solve(TreeNode *root, int targetSum, int &count)
{
    if (!root)
        return;
    // if(targetSum < 0) return; // we are not writing this line because there are negative numbers present
    if (targetSum - root->val == 0)
    {
        count++;
        // return; // we are also not writing return here because there can be paths of positive and negative numbers which can make targetsum == 0 again so if we return we cannot count those paths
    }

    solve(root->left, targetSum - root->val, count);
    solve(root->right, targetSum - root->val, count);
}

int pathSum(TreeNode *root, int targetSum)
{
    if (!root)
        return 0;
    int count = 0;

    solve(root, targetSum, count);

    return count + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
}

// Another solution without using void function for recursion
// int solve(TreeNode *root, int targetSum)
// {
//     if (!root)
//         return 0;
//     int count = 0;
//     if (root->val == targetSum)
//         count++;

//     count += solve(root->left, targetSum - root->val);
//     count += solve(root->right, targetSum - root->val);

//     return count;
// }

// int pathSum(TreeNode *root, int targetSum)
// {
//     if (!root)
//         return 0;
//     int count = 0;

//     count += solve(root, targetSum);

//     return count + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
// }

int main()
{

    return 0;
}