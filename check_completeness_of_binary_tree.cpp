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
public:
    bool isCompleteTree(TreeNode *root)
    {
        if (!root->left and !root->right)
            return true;

        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        bool isFirst;
        TreeNode *prev = NULL;

        while (!q.empty())
        {
            isFirst = true;
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                if (!isFirst and node != NULL and prev == NULL)
                    return false;

                if (node)
                    q.push(node->left);
                if (node)
                    q.push(node->right);

                prev = node;
                isFirst = false;
            }
            if (q.size() and (int) pow(2, level) != n)
                return false;
            level++;
        }

        return true;
    }
};

int main()
{

    return 0;
}