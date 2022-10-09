#include <bits/stdc++.h>
using namespace std;

/*
Intuition: we print a character at the end of t(robot's string) if it's smaller or equal any remaining characters in s.

We take the frequency of every character

We then iterate the string and add the character to stack and decrease its freq

If the top of stack is less than or equal to lowest available character in further string then we pop the characters and add them to the answer

After iteration if the stack is not empty then we pop all the characters and add it to our answer

Read in detail: https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/discuss/2678848/Stack-it-Up-!!-Easy-to-understand-c%2B%2B
*/

class Solution
{
    char getLowest(vector<int> &freq)
    {
        char ch;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
            {
                ch = 'a' + i;
                break;
            }
        }
        return ch;
    }

public:
    string robotWithString(string s)
    {
        int n = s.length();
        stack<char> st;
        string ans = "";
        vector<int> freq(26, 0);

        for (auto i : s)
        {
            freq[i - 'a']++;
        }

        for (int i = 0; i < n; i++)
        {
            st.push(s[i]);
            freq[s[i] - 'a']--;

            while (!st.empty() and getLowest(freq) >= st.top())
            {
                ans += st.top();
                st.pop();
            }
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

int main()
{

    return 0;
}