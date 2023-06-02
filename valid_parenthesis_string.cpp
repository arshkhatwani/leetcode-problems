#include <bits/stdc++.h>
using namespace std;

// https://youtu.be/QhPdNS143Qg

class Solution
{
public:
    bool checkValidString(string s)
    {
        int n = s.length(), leftMin = 0, leftMax = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                leftMin += 1;
                leftMax += 1;
            }
            else if (s[i] == ')')
            {
                leftMin -= 1;
                leftMax -= 1;
            }
            else
            {
                leftMin -= 1;
                leftMax += 1;
            }

            if (leftMax < 0)
                return false;

            leftMin = max(0, leftMin);
        }

        return leftMin == 0;
    }
};

int main()
{

    return 0;
}