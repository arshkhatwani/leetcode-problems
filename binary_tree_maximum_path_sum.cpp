#include <bits/stdc++.h>
using namespace std;

/*
At every node the maximum path can be calculated as the sum of left path and right path and node's value.
And we can compare this with our answer, if this is greater than our ans we replace our answer's value with this

So we can have a function that recursively calculates the left path and right path
And we can add both to node's val and maximise our answer like this and return the sum of max(left path, right path) and node's val from the function

Watch video to understand more: https://youtu.be/WszrfSwMz58
*/

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
    int solve(TreeNode *root, int &ans)
    {
        if (!root)
            return 0;

        int left = max(0, solve(root->left, ans));
        int right = max(0, solve(root->right, ans));

        ans = max(ans, root->val + left + right);

        return max(left, right) + root->val;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
};

int main()
{

    return 0;
}