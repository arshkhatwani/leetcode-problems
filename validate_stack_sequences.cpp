#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int i = 0, j = 0, n = pushed.size();
        stack<int> st;
        while (j < n)
        {
            if (i == n and !st.empty() and st.top() != popped[j])
                return false;
            else if (i < n and (st.empty() or st.top() != popped[j]))
            {
                st.push(pushed[i++]);
            }
            else if (!st.empty() and st.top() == popped[j])
            {
                st.pop();
                j++;
            }
        }

        return true;
    }
};

int main()
{

    return 0;
}