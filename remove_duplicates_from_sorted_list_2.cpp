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

ListNode *deleteDuplicates(ListNode *head)
{
    if (!head)
        return NULL;
    if (head->next and head->val == head->next->val)
    {
        while (head->next and head->val == head->next->val)
        {
            if (!head->next->next)
            {
                return NULL;
            }
            else
            {
                head->next = head->next->next;
            }
            if (head->next and head->val != head->next->val)
            {
                head = head->next;
            }
        }
    }

    ListNode *p = head;
    ListNode *q = head->next;

    while (q and q->next)
    {
        if (q->val == q->next->val)
        {
            while (q->next and q->val == q->next->val)
            {
                if (!q->next->next)
                    q->next = NULL;
                else
                {
                    q->next = q->next->next;
                }
            }
            p->next = q->next;
            q = q->next;
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }

    return head;
}

int main()
{

    return 0;
}