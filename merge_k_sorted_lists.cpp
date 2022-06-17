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
Push all the values of nodes in a minHeap and then pull out one by one from minheap pop them and make a new linked list and return its head
*/
class Solution
{
    void add(ListNode *head, priority_queue<int, vector<int>, greater<int>> &pq)
    {
        ListNode *p = head;

        while (p)
        {
            pq.push(p->val);
            p = p->next;
        }
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < lists.size(); i++)
        {
            add(lists[i], pq);
        }

        ListNode *head = new ListNode();
        ListNode *p = head;

        while (!pq.empty())
        {
            p->next = new ListNode(pq.top());

            pq.pop();
            p = p->next;
        }

        return head->next;
    }
};

/*
This is using merge with divide and conquer, see leetcode solution appraoch 5 and image to understand more
*/
class Solution
{
    ListNode *merge(ListNode *head1, ListNode *head2)
    {
        ListNode *dummy = new ListNode();
        ListNode *p = dummy;

        while (head1 and head2)
        {
            p->next = new ListNode();

            if (head1->val > head2->val)
            {
                p->next->val = head2->val;
                head2 = head2->next;
            }
            else
            {
                p->next->val = head1->val;
                head1 = head1->next;
            }

            p = p->next;
        }

        while (head1)
        {
            p->next = new ListNode();
            p->next->val = head1->val;

            head1 = head1->next;
            p = p->next;
        }

        while (head2)
        {
            p->next = new ListNode();
            p->next->val = head2->val;

            head2 = head2->next;
            p = p->next;
        }

        return dummy->next;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.size() == 0)
            return NULL;
        if (lists.size() == 1)
            return lists[0];

        int n = lists.size();
        while (n > 1)
        {
            n = lists.size();
            vector<ListNode *> a;
            int i = 0;

            for (i = 0; i < n - 1; i += 2)
            {
                ListNode *head = merge(lists[i], lists[i + 1]);
                a.push_back(head);
            }

            while (i < n)
            {
                a.push_back(lists[i]);
                i++;
            }

            lists = a;
        }

        return lists[0];
    }
};

int main()
{

    return 0;
}