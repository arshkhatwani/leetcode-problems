#include <bits/stdc++.h>
using namespace std;

/*
String only has 2 chars, so if the overall string is palindromic then answer is 1

else we know that 2 palindromic subsequences can be formed one of a(s) like aaaaa... and one of b(s) like bbbbb... so the answer will be 2 in this case
*/

class Solution
{
public:
    int removePalindromeSub(string s)
    {
        int n = s.length();
        int i = 0, j = n - 1;

        while (i < j)
        {
            if (s[i] == s[j])
                i++, j--;
            else
                return 2;
        }

        return 1;
    }
};

int main()
{

    return 0;
}