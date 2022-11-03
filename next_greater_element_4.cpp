#include <bits/stdc++.h>
using namespace std;

/*
First for every element(say x) keep track of elements(store their indices) whose next greater element is 'x'

Then iterate again and this time for every element (say x), iterate in the indices stored in above step for x
Then for each of these indices binary search the monotonic stack and find the element which is just greater than the element present at that iterating index

In order to do binary search in the stack we use a vector second time in place of a stack and we maintain the vector/array in monotonic decreasing order just like we maintain the stack. And for binary search we will use upper bound on that array

TC: O(nlogn)
SC: O(n)
*/

class Solution
{
public:
    vector<int> secondGreaterElement(vector<int> &a)
    {
        int n = a.size();
        vector<vector<int>> nge(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            if (!st.empty() and a[st.top()] > a[i])
            {
                nge[st.top()].push_back(i);
            }
            else
            {
                while (!st.empty() and a[st.top()] <= a[i])
                {
                    st.pop();
                }
                if (!st.empty())
                {
                    nge[st.top()].push_back(i);
                }
            }
            st.push(i);
        }

        vector<int> st2;
        vector<int> ans(n, -1);
        for (int i = n - 1; i >= 0; i--)
        {

            for (int j = 0; j < nge[i].size(); j++)
            {
                int el = a[nge[i][j]];

                auto itr = upper_bound(st2.rbegin(), st2.rend(), el) - st2.rbegin();
                itr = st2.size() - 1 - itr;

                if (itr != st2.size() and itr >= 0)
                {
                    ans[nge[i][j]] = st2[itr];
                }
            }

            while (!st2.empty() and st2[st2.size() - 1] <= a[i])
                st2.pop_back();
            st2.push_back(a[i]);
        }

        return ans;
    }
};

int main()
{

    return 0;
}