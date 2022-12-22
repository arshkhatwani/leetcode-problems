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
If we know the sum of a subtree,
the answer is max((total_sum - subtree_sum) * subtree_sum) in each node.
*/

class Solution
{
    long long ans = 0, total = 0;
    long long sum(TreeNode *root)
    {
        if (!root)
            return 0;

        long long sumLeft = sum(root->left);
        long long sumRight = sum(root->right);
        long long s = root->val + sumLeft + sumRight;

        ans = max(ans, s * (total - s));

        return s;
    }

public:
    int maxProduct(TreeNode *root)
    {
        total = sum(root);
        sum(root);
        long long MOD = 1e9 + 7;
        return ans % MOD;
    }
};

int main()
{

    return 0;
}