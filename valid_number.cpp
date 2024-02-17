#include <bits/stdc++.h>
using namespace std;

/*
If there is 'e' or 'E' present, We can separate the number into 2 parts: left, right.
- Left part can be checked if it is decimal or not
- Right part can be checked if it is integer or not

Suppose we do not find any of 'e' or 'E', we just check if a number is decimal or not(an integer will also pass the decimal test)
*/

class Solution
{
    bool isDecimal(string s)
    {
        int n = s.length();
        bool hasPeriod = s[0] == '.' ? true : false;
        bool hasSign = s[0] == '+' or s[0] == '-' ? true : false;
        bool hasDigit = s[0] >= '0' and s[0] <= '9' ? true : false;

        if (!n)
            return false;
        if (s[0] != '.' and s[0] != '+' and s[0] != '-' and (s[0] < '0' or s[0] > '9'))
            return false;
        if ((s[0] == '.' or s[0] == '+' or s[0] == '-') and n == 1)
            return false;

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == '.' and hasPeriod)
                return false;
            if (s[i] == '.')
                hasPeriod = true;
            else if (s[i] < '0' or s[i] > '9')
                return false;
            else
                hasDigit = true;
        }

        if ((hasPeriod or hasSign) and !hasDigit)
            return false;

        return true;
    }
    bool isInteger(string s)
    {
        int n = s.length();
        if (!n)
            return false;
        if (s[0] != '+' and s[0] != '-' and (s[0] < '0' or s[0] > '9'))
            return false;
        if ((s[0] == '+' or s[0] == '-') and n == 1)
            return false;

        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] < '0' or s[i] > '9')
                return false;
        }

        return true;
    }

public:
    bool isNumber(string s)
    {
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'e' or s[i] == 'E')
            {
                string leftNum = s.substr(0, i);
                string rightNum = s.substr(i + 1, n - i - 1);
                return isDecimal(leftNum) and isInteger(rightNum);
            }
        }
        return isDecimal(s);
    }
};

int main()
{

    return 0;
}