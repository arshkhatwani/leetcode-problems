#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// Level order traversal solution
// TC: O(n), SC: O(n)
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            Node *prev = NULL;

            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

                if (prev)
                    prev->next = node;
                prev = node;
            }
        }

        return root;
    }
};

// Space optimised iterative solution
// Logic video: https://youtu.be/U4hFQCa1Cq0
class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *cur = root;
        Node *nxt = root ? root->left : NULL;

        while (cur and nxt)
        {
            if (cur->left)
                cur->left->next = cur->right;

            if (cur->next and cur->right)
                cur->right->next = cur->next->left;

            cur = cur->next;

            if (!cur)
            {
                cur = nxt;
                nxt = cur->left;
            }
        }

        return root;
    }
};

int main()
{

    return 0;
}