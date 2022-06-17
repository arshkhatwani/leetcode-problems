#include <bits/stdc++.h>
using namespace std;

// Watch video to understand https://youtu.be/Q2Tw6gcVEwc

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;

        int n = s.length(), increment = 2 * (numRows - 1);
        string ans = "";

        for (int r = 0; r < numRows; r++)
        {
            for (int i = r; i < n; i += increment)
            {
                ans += s[i];

                if (r > 0 and r < numRows - 1 and i + increment - (2 * r) < n)
                {
                    ans += s[i + increment - 2 * r];
                }
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}