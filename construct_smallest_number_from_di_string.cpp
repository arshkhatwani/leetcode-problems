#include <bits/stdc++.h>
using namespace std;

/*
Logic video: https://youtu.be/38XAg_JZ-zk
*/

class Solution
{
public:
    string smallestNumber(string pattern)
    {
        int n = pattern.length();
        string ans = "";
        for (char i = '1'; i - '1' < n + 1; i++)
            ans += i;

        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (i < n and pattern[i] == pattern[j])
                i++;
            i--;

            if (pattern[j] == 'D')
                reverse(ans.begin() + j, ans.begin() + i + 2);
        }

        return ans;
    }
};

int main()
{

    return 0;
}