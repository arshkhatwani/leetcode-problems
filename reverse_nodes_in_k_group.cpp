#include <bits/stdc++.h>
using namespace std;

/*
Basically we are traversing the list and keep count of nodes and everytime when we reach kth node we cut it from the list and we take that partial linked list and reverse it and then join it with the overall list and reset our count to 1 and then continue our iteration, we keep track of newHead everytme when we reset the count
*/

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    ListNode *reverse(ListNode *head)
    {
        if (!head or !head->next)
            return head;

        ListNode *newHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }

    ListNode *getEndNode(ListNode *head)
    {
        ListNode *p = head;

        while (p->next)
        {
            p = p->next;
        }

        return p;
    }

    void traverse(ListNode *head)
    {
        ListNode *p = head;
        while (p)
        {
            cout << p->val << " ";
            p = p->next;
        }
        cout << endl;
    }

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head->next)
            return head;

        int n = 1;
        ListNode *p = head;
        ListNode *q = head;
        ListNode *oldTail = NULL;

        ListNode *newHead = NULL;

        while (p and q)
        {
            if (n == k)
            {
                ListNode *newQ = q->next;

                q->next = NULL;
                p = reverse(p);

                // traverse(p);

                if (!newHead)
                    newHead = p;

                q = getEndNode(p);
                q->next = newQ == NULL ? NULL : newQ;
                if (oldTail)
                    oldTail->next = p;

                oldTail = q;
                p = q = newQ == NULL ? NULL : newQ;
                n = 1;
            }

            if (q)
                q = q->next;
            n++;
        }

        return newHead;
    }
};

int main()
{

    return 0;
}