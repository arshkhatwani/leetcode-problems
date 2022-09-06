#include <bits/stdc++.h>
using namespace std;

/*
We can use a monotonic increasing stack because we have to remove the bigger digits at most significant places on left.

For every digit we check if the previously inserted digit is greater or not if it is then we will keep popping until the stack's top would get <= current digit and we will do this operation at most k times only

Now if we didnt have to pop any element because say the given string was sorted so after the iteration we would remove top k elements from the stack (see the code to understand)
*/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        int n = num.length();

        if (!k)
            return num;
        if (n <= k)
            return "0";

        stack<char> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and k and st.top() > num[i])
            {
                st.pop();
                k--;
            }

            if (st.empty() and num[i] == '0') // preventing leading zeroes
                continue;

            st.push(num[i]);
        }

        while (k and !st.empty()) // removing k remaining digits
        {
            st.pop();
            k--;
        }

        num = string(st.size(), '0');
        n = st.size();
        while (!st.empty())
        {
            num[n - 1] = st.top();
            n--;
            st.pop();
        }

        if (num == "")
            num = "0";

        return num;
    }
};

int main()
{

    return 0;
}