#include <bits/stdc++.h>
using namespace std;

/*
DP and Stack Approach
Create a dp array with every element to 0 where ith index will be used to store the length of substring till 'i' also take a stack
Iterate the string
    If we get '(' we push its index into the stack

    Else if we get ')' we then check if the stack is not empty then we pop the top and set dp[i] to (i - top) and if the (top > 0) then we add dp[top-1] to dp[i] because we need to add the prev valid string (if any) to the answer
    We maintain a maxLen variable to keep track of the maximum length

DP Approach
See leetcode's DP solution to understand the approach

Stack only approach
Take a stack push -1 into it
Iterate the string
    If we get '(' we push it into stack

    Else if pop the element from stack and then we check if stack is empty we push i (i.e index of ')') into the stack. Else if the stack is not empty we maximise the asnwer by comparing it with (i - st.top())

Constant space approach
We take 2 counters open and close

We first iterate from left to right and increment 'open' when we encounter '(' and increment 'close' when we encounter ')' anytime we get open == close we try to maximise our answer comparing it with (open + close), if we get clsoe > open we reset both counters to 0

We then iterate from right to left and follow the similar procedure but this time we reset counters only if open > close
*/

// DP and Stack
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.length(), maxLen = 0;
        vector<int> dp(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else if (!st.empty())
            {
                int top = st.top();
                st.pop();
                dp[i] = i - top + 1;
                if (top > 0)
                    dp[i] += dp[top - 1];
            }

            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};

// DP
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int n = s.length(), maxLen = 0;
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (i == 0 or s[i] == '(')
                continue;

            if (s[i - 1] == '(')
            {
                dp[i] = (i > 1 ? dp[i - 2] : 0) + 2;
            }
            else if (i - dp[i - 1] > 0 and s[i - dp[i - 1] - 1] == '(')
            {
                dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
            }

            maxLen = max(maxLen, dp[i]);
        }

        return maxLen;
    }
};

// Stack
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        int n = s.length(), maxLen = 0;
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    maxLen = max(maxLen, i - st.top());
                }
            }
        }

        return maxLen;
    }
};

// Constant space
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int open = 0, close = 0, n = s.length(), maxLen = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close)
            {
                maxLen = max(maxLen, open + close);
            }
            if (open < close)
            {
                open = close = 0;
            }
        }

        open = close = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '(')
                open++;
            else
                close++;

            if (open == close)
            {
                maxLen = max(maxLen, open + close);
            }
            if (close < open)
            {
                open = close = 0;
            }
        }

        return maxLen;
    }
};

int main()
{

    return 0;
}