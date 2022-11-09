#include <bits/stdc++.h>
using namespace std;

/*
This problem can be solved using priority queue and two pointers
*/

// Double Priority Queue
class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        priority_queue<int, vector<int>, greater<int>> pq1, pq2;
        int n = costs.size(), i = 0, j = n - 1;
        long long ans = 0;

        while (k--)
        {
            while (pq1.size() < candidates and i <= j)
                pq1.push(costs[i++]);
            while (pq2.size() < candidates and j >= i)
                pq2.push(costs[j--]);

            int a = !pq1.empty() ? pq1.top() : INT_MAX;
            int b = !pq2.empty() ? pq2.top() : INT_MAX;

            if (a <= b)
            {
                pq1.pop();
                ans += a;
            }
            else
            {
                pq2.pop();
                ans += b;
            }
        }

        return ans;
    }
};

// Single Priority Queue
struct triplet
{
    int first, second, third;
    triplet(vector<int> a)
    {
        first = a[0];
        second = a[1];
        third = a[2];
    }
};

struct comp
{
    bool operator()(const triplet &a, const triplet &b)
    {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first > b.first;
    }
};

class Solution
{
public:
    long long totalCost(vector<int> &costs, int k, int candidates)
    {
        int n = costs.size();
        int i = 0, j = n - 1;
        priority_queue<triplet, vector<triplet>, comp> pq;

        for (i = 0; i < candidates; i++)
            pq.push(triplet({costs[i], i, true}));
        for (j = n - 1; j > i and n - 1 - j < candidates; j--)
            pq.push(triplet({costs[j], j, false}));

        i--;
        j++;

        long long ans = 0;
        while (k--)
        {
            triplet top = pq.top();
            pq.pop();
            ans += top.first;

            if (j - i >= 1)
            {
                if (top.third)
                {
                    i++;
                    if (i != j)
                    {
                        pq.push(triplet({costs[i], i, true}));
                    }
                }
                else
                {
                    j--;
                    if (i != j)
                    {
                        pq.push(triplet({costs[j], j, false}));
                    }
                }
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}