#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    int n = s.length();
    string ans = "", x = "";
    int size = 0;

    for (int i = n - 1; i >= -1; i--)
    {
        if (i == -1 or s[i] == ' ')
        {
            if (size != 0)
            {
                ans += s.substr(i + 1, size) + ' ';
                size = 0;
            }
            continue;
        }
        else
        {
            size++;
        }
    }

    if (ans[ans.size() - 1] == ' ')
        ans = ans.substr(0, ans.size() - 1);

    return ans;
}

int main()
{

    return 0;
}