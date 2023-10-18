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
HINT: Inorder traversal of BST returns a sorted array
Video: https://youtu.be/9TJYWh0adfk?si=cNIBqUCgBjqnWodo
*/

class Solution
{
    void inorder(TreeNode *root, int &k, int &count, int &ans)
    {
        if (!root)
            return;

        inorder(root->left, k, count, ans);

        count++;
        if (count == k)
            ans = root->val;

        inorder(root->right, k, count, ans);
    }

public:
    int kthSmallest(TreeNode *root, int k)
    {
        int ans = -1, count = 0;
        inorder(root, k, count, ans);
        return ans;
    }
};

int main()
{

    return 0;
}