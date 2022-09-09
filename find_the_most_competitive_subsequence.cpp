#include <bits/stdc++.h>
using namespace std;

/*
Take an empty array 'ans' of size k and a variable j = 0 for tracking 'ans'
Calculate next smaller element from right for the given array
If an element at ans is nothing set ans[j]=-1
Now, if nse[ans[j]] cannot give k elements further it (including itself) then increment j, decrement k because we have found the best element for that position

Else set ans[j] = nse[i] and i = nse[i] - 1
we do this because there's no point in iterating till nse and since we need elements which are further than nse we directly jump to nse in our next iteration

// Better solution (single pass)
https://leetcode.com/problems/find-the-most-competitive-subsequence/discuss/952786/JavaC%2B%2BPython-One-Pass-Stack-Solution
*/

// Better solution
class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &a, int k)
    {
        int n = a.size();
        vector<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and st.back() > a[i] and st.size() - 1 + a.size() - i >= k)
            {
                st.pop_back();
            }
            if (st.size() < k)
                st.push_back(a[i]);
        }

        return st;
    }
};

class Solution
{
    vector<int> nseFromRight(vector<int> &a)
    {
        stack<int> s;
        int n = a.size();
        vector<int> nse(n);

        for (int i = n - 1; i >= 0; i--)
        {
            while (!s.empty() and a[s.top()] >= a[i])
            {
                s.pop();
            }

            nse[i] = !s.empty() ? s.top() : n;

            s.push(i);
        }

        return nse;
    }

public:
    vector<int> mostCompetitive(vector<int> &a, int k)
    {
        int n = a.size(), j = 0;
        vector<int> nse = nseFromRight(a);
        vector<int> ans(k, -1);

        for (int i = 0; i < n && j < ans.size(); i++)
        {
            if (ans[j] == -1)
                ans[j] = i;

            if (n - nse[ans[j]] < k)
            {
                j++;
                k--;
            }
            else
            {
                ans[j] = nse[i];
                i = nse[i] - 1;
            }
        }

        for (int i = 0; i < ans.size(); i++)
        {
            ans[i] = a[ans[i]];
        }

        return ans;
    }
};

int main()
{

    return 0;
}