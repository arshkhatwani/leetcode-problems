#include <bits/stdc++.h>
using namespace std;

/*
Since we are in a BST, the LCA would be basically the last point of split in the BST

For example if the given BST is
     0
    / \
  -1   1
      / \
    -2   3
Here, LCA(-2,3) = 1

For cases where both the nodes are on one side
     6
    / \
   2   8
  / \
 0   4
Here, LCA(2,4) = 2

Video: https://youtu.be/cX_kPV_foZc?si=BA4wcUmljcbu59ac
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;

        if (p->val < root->val and q->val < root->val)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        if (p->val > root->val and q->val > root->val)
        {
            return lowestCommonAncestor(root->right, p, q);
        }

        return root;
    }
};

int main()
{

    return 0;
}