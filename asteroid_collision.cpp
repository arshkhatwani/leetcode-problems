#include <bits/stdc++.h>
using namespace std;

/*
We can use a stack to keep track of non colliding asteroids
See the code to understand
*/

class Solution
{
    bool willCollide(int p1, int p2)
    {
        if (p1 > 0 and p2 > 0)
            return false;
        if (p1 < 0 and p2 < 0)
            return false;
        if (p1 < 0 and p2 > 0)
            return false;
        return true;
    }

public:
    vector<int> asteroidCollision(vector<int> &a)
    {
        stack<int> st;
        int n = a.size();

        for (int i = 0; i < n; i++)
        {
            if (st.empty() or !willCollide(st.top(), a[i]))
            {
                st.push(a[i]);
                continue;
            }

            bool flag = false;
            while (!st.empty() and willCollide(st.top(), a[i]))
            {
                if (abs(st.top()) > abs(a[i]))
                {
                    flag = true;
                    break;
                }
                else if (abs(st.top()) == abs(a[i]))
                {
                    flag = true;
                    st.pop();
                    break;
                }
                else
                {
                    st.pop();
                }
            }

            if (!flag)
            {
                st.push(a[i]);
            }
        }

        vector<int> ans(st.size());
        int i = st.size() - 1;
        while (!st.empty())
        {
            ans[i] = st.top();
            st.pop();
            i--;
        }

        return ans;
    }
};

int main()
{

    return 0;
}