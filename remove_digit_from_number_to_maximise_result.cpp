#include <bits/stdc++.h>
using namespace std;

/*
We can generate all strings, and compare them to find the largest. That, however, would be quite wasteful.

Instead, we can just remove the leftmost digit if it's followed by a larger number. If we cannot find such case, we remove the last occurence of digit.
*/

class Solution
{
public:
    string removeDigit(string s, char digit)
    {
        int n = s.length(), last;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == digit and s[i] < s[i + 1])
            {
                return s.substr(0, i) + s.substr(i + 1);
            }

            if (s[i] == digit)
                last = i;
        }

        return s.substr(0, last) + s.substr(last + 1);
    }
};

int main()
{

    return 0;
}