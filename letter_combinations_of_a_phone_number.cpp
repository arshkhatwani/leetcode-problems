#include <bits/stdc++.h>
using namespace std;

/*
The idea is to traverse every string of letters attached to the given string of numbers
And while traversing the letters string, make a recursive call to the next number in the given number string
*/

class Solution
{
    vector<string> ans;
    unordered_map<char, string> mp;

    void f(int i, int n, string &a, string s)
    {
        if (i == n)
        {
            ans.push_back(s);
            return;
        }

        string letters = mp[a[i]];
        for (int k = 0; k < letters.length(); k++)
        {
            f(i + 1, n, a, s + letters[k]);
        }
    }

public:
    vector<string> letterCombinations(string a)
    {
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        ans.clear();

        if (!a.length())
            return ans;

        f(0, a.length(), a, "");

        return ans;
    }
};

int main()
{

    return 0;
}