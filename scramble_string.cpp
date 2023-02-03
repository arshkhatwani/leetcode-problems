#include <bits/stdc++.h>
using namespace std;

/*
Lets say there are two strings, and we partition them as follows

s1 -> a b c d e f
     -x1-|---y1--|

      ----q--|--p-
s2 -> b c d a e f
      -x2-|---y2--|

if (x == x1 and y == y1) then they are scramble strings
OR
if (x == p and y == q) then they are scramble strings

See the memoisation code to understand recursion

Base condition
- If both strings are of length 1 then we return s1 == s2 (i.e whether s1 is equal to s2 or not)
- If both strings are of some length and are equal then we do not need to call the recursion further and we return 'true'

Pruning (Optimisation to avoid unnecessary recursion calls)
Here before partioning the strings we can count the frequency of characters in both the strings separately and if the frequency is not equal then we know that they cannot be scramble strings so we do not need to partition them and return false then and there itself

This pruning will not change the time complexity of worst test cases but will make the avg and best test cases faster


Refer video to understand above logic in detail: https://youtu.be/MDmZm_aVDF8
*/

// Memoisation + Pruning
class Solution
{
    unordered_map<string, bool> dp;

public:
    bool isScramble(string s1, string s2)
    {
        if (s1.length() == 1)
            return s1 == s2;
        if (s1 == s2)
            return true;

        string check = s1 + '*' + s2;
        if (dp.find(check) != dp.end())
            return dp[check];

        int n = s1.length();
        vector<int> count1(26, 0), count2(26, 0);
        for (int i = 0; i < n; i++)
        {
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        if (count1 != count2)
            return dp[check] = false;

        bool ans = false;
        for (int i = 0; i < n - 1; i++)
        {
            string x1 = s1.substr(0, i + 1);
            string y1 = s1.substr(i + 1);

            string x2 = s2.substr(0, i + 1);
            string y2 = s2.substr(i + 1);

            string p = s2.substr(0, n - i - 1);
            string q = s2.substr(n - i - 1);

            ans = ans or (isScramble(x1, x2) and isScramble(y1, y2));
            ans = ans or (isScramble(x1, q) and isScramble(y1, p));
        }

        dp[check] = ans;

        return ans;
    }
};

// Memoisation
class Solution
{
    unordered_map<string, bool> dp;

public:
    bool isScramble(string s1, string s2)
    {
        if (s1.length() == 1)
            return s1 == s2;
        if (s1 == s2)
            return true;

        string check = s1 + '*' + s2;
        if (dp.find(check) != dp.end())
            return dp[check];

        int n = s1.length();
        bool ans = false;
        for (int i = 0; i < n - 1; i++)
        {
            string x1 = s1.substr(0, i + 1);
            string y1 = s1.substr(i + 1);

            string x2 = s2.substr(0, i + 1);
            string y2 = s2.substr(i + 1);

            string p = s2.substr(0, n - i - 1);
            string q = s2.substr(n - i - 1);

            ans = ans or (isScramble(x1, x2) and isScramble(y1, y2));
            ans = ans or (isScramble(x1, q) and isScramble(y1, p));
        }

        dp[check] = ans;

        return ans;
    }
};

int main()
{

    return 0;
}