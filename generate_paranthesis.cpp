#include <bits/stdc++.h>
using namespace std;

/*
At every point we have 2 choices:
1. Add an open bracket
2. Add a close bracket

Now these 2 choices will be valid on some conditions:
We can only add an open bracket if we have open brackets left to add (i.e used open brackets < n)

We can only add a close bracket if we have open brackets(i.e current open brackets > 0)

See recursive diagram and code to understand more
*/

class Solution
{
    vector<string> ans;

    void solve(int n, int open, string s)
    {
        if (n == 0)
        {
            ans.push_back(s);
            return;
        }

        if (open)
            solve(n - 1, open - 1, s + ')');

        if (open < n)
            solve(n, open + 1, s + '(');
    }

public:
    vector<string> generateParenthesis(int n)
    {
        ans.clear();
        string s = "";
        solve(n, 0, s);
        return ans;
    }
};

int main()
{

    return 0;
}