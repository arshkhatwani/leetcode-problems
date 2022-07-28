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

/*
We can have 3 pointers => prev, cur, fow

we can apply the following logic:

// To swap
cur->next = fow->next
fow->next = cur
pre->next = fow

// To move on to next node
pre = cur
cur = cur->next
fow = cur->next

We can perform the above operations till fow gets NULL
*/

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head or !head->next)
            return head;

        ListNode *pre = NULL;
        ListNode *cur = head;
        ListNode *fow = head->next;
        ListNode *newHead = head->next;

        while (fow)
        {
            cur->next = fow->next;
            fow->next = cur;
            if (pre)
                pre->next = fow;

            pre = cur;
            cur = cur->next;
            fow = cur ? cur->next : NULL;
        }

        return newHead;
    }
};

int main()
{

    return 0;
}