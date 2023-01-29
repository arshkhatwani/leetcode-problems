#include <bits/stdc++.h>
using namespace std;

/*
Since there can be any number of moves we can look for scenarios regarding when conversion is possible and when it is not

So lets say the given string has 1s (any count greater than 0) and target string has 0 count of 1s. In this case the conversion is not possible

Lets say the given string has 0 1s and target string has some amount of 1s then also the conversion is not possible

In all the other cases whether both string has equal or unequal amount of 1s the conversion is possible
This is because if you want to convert a '1' to '0' you would need an extra '1'
and if you want to convert a '0' to '1' you would again need an extra '1'

See the code to understand more
Can also read this article https://leetcode.com/problems/apply-bitwise-operations-to-make-strings-equal/solutions/3083831/java-c-python-1-line-check-1/
*/

class Solution
{
public:
    bool makeStringsEqual(string s, string target)
    {
        int n = s.length(), count1s = 0, countTarget1s = 0;

        for (int i = 0; i < n; i++)
        {
            count1s += (s[i] == '1');
            countTarget1s += (target[i] == '1');
        }

        if (count1s > 0 and countTarget1s == 0)
            return false;
        if (count1s == 0 and countTarget1s > 0)
            return false;

        return true;
    }
};

int main()
{

    return 0;
}