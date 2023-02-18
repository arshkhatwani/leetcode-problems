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
Method 1:
We can get the inorder traversal of the tree, since it is BST then the inorder traversal will be a sorted array of nodes
Then we can start iterating from 1st index and for every element we can calculate the diff between that element and its previous element and maintain a 'ans' variable to store the minimum of the difference
TC: O(n)
SC: O(h) + O(n)


Method 2:
This method is the optimised form of method 1, we know that we need the previous element to calculate the diff so we can also say that for every node we need its inorder preprocessor. So this can be handled inside the recursion with a global variable that stores previous value.

So a variable 'prevValue' can store the value of the node we traversed previously in the in-order traversal. This way, we don't have to store the elements in an array and, at the same time, don't have to re-iterate over the nodes again.
TC: O(n)
SC: O(h)

See the code to understand.
*/

class Solution
{
    int prevVal = INT_MAX;
    void inorder(TreeNode *root, int &ans)
    {
        if (!root)
            return;

        inorder(root->left, ans);

        if (prevVal != INT_MAX)
            ans = min(ans, root->val - prevVal);

        prevVal = root->val;
        inorder(root->right, ans);
    }

public:
    int minDiffInBST(TreeNode *root)
    {
        prevVal = INT_MAX;
        int ans = INT_MAX;
        inorder(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}