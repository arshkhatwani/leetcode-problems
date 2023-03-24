#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
By observation its seen that to construct a height balanced BST we need to make the root from center of the list and then do the same process recursively for left and right parts of the linked list

See the code to understand more
*/

class Solution
{
    TreeNode *build(ListNode *start, ListNode *end)
    {
        if (!start or !end)
            return NULL;
        if (start == end->next)
            return NULL;
        if (start == end)
            return new TreeNode(start->val);

        ListNode *slow = start, *fast = start->next, *prev = NULL;
        while (fast != end)
        {
            if (fast->next != NULL and fast->next != end)
                fast = fast->next->next;
            else
                fast = end;
            prev = slow;
            slow = slow->next;
        }

        TreeNode *node = new TreeNode(slow->val);
        node->left = build(start, prev);
        node->right = build(slow->next, end);

        return node;
    }

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return NULL;

        ListNode *last = head;
        while (last->next)
            last = last->next;

        return build(head, last);
    }
};

int main()
{

    return 0;
}