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
INTUITION:
In the string,
if the current node's depth == prev node's depth + 1
    Then we know that current node is a child of prev node
If current node's depth == prev node's depth
    Then we know that current node is a sibling of prev node (i.e both nodes share same parent)
If current node's depth < prev node's depth
    Then we need to go to upper nodes because current node is right child of some upper node

APPROACH:
We iterate the string and get the nodes and the depth of them (numbr of '-' before them)
After getting the nodes in pairs we make a treeNode of that value and push them into the stack

If the depth of stack's top is >= to the current node's depth then we keep popping the stack till depth of stack's top < current node's depth

Then we link the current node with stack's top's either left child or right child(if left child is already present)

After the end of the iteration we return the root of binary tree i.e the first node that was pushed into the stack

TC: O(s) s is length of string
SC: O(n) n is number of nodes
*/

class Solution
{
public:
    TreeNode *recoverFromPreorder(string traversal)
    {
        int n = traversal.length();
        char prev = '-';
        int count = 0, num = 0;

        stack<pair<TreeNode *, int>> st;
        TreeNode *root = NULL;

        for (int i = 0; i <= n; i++)
        {
            if (i < n and traversal[i] >= '0' and traversal[i] <= '9')
            {
                num = num * 10 + (traversal[i] - '0');
            }
            else if (i == n or traversal[i] == '-' and prev >= '0' and prev <= '9')
            {
                TreeNode *node = new TreeNode(num);

                if (st.empty())
                {
                    root = node;
                }
                else
                {
                    while (!st.empty() and st.top().second >= count)
                        st.pop();

                    TreeNode *topNode = st.top().first;

                    if (!topNode->left)
                        topNode->left = node;
                    else
                        topNode->right = topNode->right = node;
                }

                st.push({node, count});

                num = 0;
                count = 1;
            }
            else if (traversal[i] == '-')
            {
                count++;
            }

            prev = traversal[i];
        }

        return root;
    }
};

int main()
{

    return 0;
}