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
The logic is to do DFS and find out the sum of left and right subtrees and then calculate,
total sum = sum of left subtree + sum of right subtree + root's value
Then store the frequency of the total sum in a map
And then return it in recursive function
*/

class Solution
{
    unordered_map<int, int> mp;

    int sum(TreeNode *root)
    {
        if (!root)
            return 0;

        int leftSum = sum(root->left);
        int rightSum = sum(root->right);

        int subTreeSum = root->val + leftSum + rightSum;

        mp[subTreeSum]++;

        return subTreeSum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode *root)
    {
        sum(root);

        vector<int> ans;
        int maxCount = INT_MIN;

        for (auto i : mp)
        {
            if (i.second > maxCount)
            {
                maxCount = i.second;
                ans.clear();
            }

            if (i.second == maxCount)
                ans.push_back(i.first);
        }

        return ans;
    }
};

int main()
{

    return 0;
}