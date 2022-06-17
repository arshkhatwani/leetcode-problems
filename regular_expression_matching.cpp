#include <bits/stdc++.h>
using namespace std;

/*
If we get equal letters or one of them is '.' AND next element in p is '*'
Then we have 3 choices,
    1. Increment both the indices (i.e bss ek match karna hai aur aage chlte hai is '*' ke)
    2. Increment only the string idx (i.e aur match karne ka mann hai)
    3. Increment the pattern idx (i.e matching nahi karni koi kyuki '*' hai so acc. to ques. 0 occurence ho uss '*' ke phle wale element ko toh bhi chlega)

If we get just equal letters or one of them is '.'
Then we only have one choice,
    1. Increment both the indices(i.e match kiya dono ko aur aage chal pade)

If nothing is getting matched then just increment the string idx

BASE CASES:
If both the string and pattern are ended return true
If the string has ended just check the remaining pattern if that pattern is only left with '*' wale elements then just return true else return false

Now to check the pattern just simply run a for loop and check the count of chars and stars if they're equal then return true else return false

Also watch this: https://youtu.be/HAA8mgxlov8
*/

// My solution
class Solution
{
    vector<vector<int>> dp;

    bool f(int i, int j, string &s, string &p)
    {
        if (i == s.length() and j == p.length())
            return true;

        if (i == s.length())
        {
            int stars = 0, letters = 0;
            for (int k = j; k < p.length(); k++)
            {
                if (p[k] == '*')
                    stars++;
                else
                    letters++;
            }

            return dp[i][j] = stars == letters;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        bool equalCond = s[i] == p[j] or p[j] == '.';
        bool ans = false;

        if (j + 1 < p.length() and p[j + 1] == '*')
        {
            if (equalCond)
                ans = ans or f(i + 1, j + 2, s, p);
            if (equalCond)
                ans = ans or f(i + 1, j, s, p);

            ans = ans or f(i, j + 2, s, p);
        }

        else if (equalCond)
        {
            ans = ans or f(i + 1, j + 1, s, p);
        }

        return dp[i][j] = ans;
    }

public:
    bool isMatch(string s, string p)
    {
        int m = s.length(), n = p.length();
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));

        return f(0, 0, s, p);
    }
};

int main()
{

    return 0;
}