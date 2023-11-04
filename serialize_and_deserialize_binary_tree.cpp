#include <bits/stdc++.h>
using namespace std;

// Logic: https://youtu.be/-YbXySKJsX8?si=yqhA5ttScQv0AKK6

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";
        string s;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node == NULL)
                s += "#,";
            else
                s += to_string(node->val) + ",";

            if (node)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.length() == 0)
            return NULL;
        queue<TreeNode *> q;
        string num;
        stringstream s(data);

        getline(s, num, ',');
        TreeNode *root = new TreeNode(stoi(num));
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            getline(s, num, ',');
            if (num != "#")
            {
                TreeNode *leftNode = new TreeNode(stoi(num));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, num, ',');
            if (num != "#")
            {
                TreeNode *rightNode = new TreeNode(stoi(num));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

int main()
{

    return 0;
}