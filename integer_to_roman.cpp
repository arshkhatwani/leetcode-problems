#include <bits/stdc++.h>
using namespace std;

/* The code itself is understandable */

class Solution
{
public:
    string intToRoman(int num)
    {
        vector<string> ro = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

        string ans = "";

        for (int i = 0; num != 0; i++)
        {
            while (num >= val[i])
            {
                num -= val[i];
                ans += ro[i];
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}