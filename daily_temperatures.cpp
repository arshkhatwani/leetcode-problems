#include <bits/stdc++.h>
using namespace std;

/*
The logic for this problem is exactly same as the Online Stock Span Problem
We take a stack of pairs (element, days after which we get warmer temperature) and traverse from end to start of the given array
If the stack is empty or s.top() > a[i] then we push the element in the stack with value 1

Else we keep popping until the stack gets empty or s.top() > a[i] and also we keep adding the the second values of pairs to our current pair and then push it into stack

There is another approach that uses O(1) extra space, which has the same intuition, just some optimisation
*/

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &a)
    {
        int n = a.size(), count;

        stack<pair<int, int>> s;
        vector<int> ans(n, -1);

        for (int i = n - 1; i >= 0; i--)
        {
            count = 1;

            while (!s.empty() and s.top().first <= a[i])
            {
                count += s.top().second;
                s.pop();
            }

            if (s.empty())
                count = 0;

            s.push({a[i], count});
            ans[i] = count;
        }

        return ans;
    }
};

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &a)
    {
        int n = a.size(), hottest = 0, days;
        vector<int> ans(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            if (hottest <= a[i])
            {
                hottest = a[i];
                continue;
            }

            days = 1;
            while (a[i + days] <= a[i])
            {
                days += ans[i + days];
            }

            ans[i] = days;
        }

        return ans;
    }
};

int main()
{

    return 0;
}