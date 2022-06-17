#include <bits/stdc++.h>
using namespace std;

/*
What's happening here is that

countAndSay(1) = 1

countAndSay(2) = Read result of countAndSay(1) and then convert it into a number
=> 1 => one 1 => 11
countAndSay(2) = 11

countAndSay(3) = Read result of countAndSay(2) and then convert it into a number
=> 11 => two 1's => 21
countAndSay(3) = 21

countAndSay(4) = same procedure => 21 => one 2 one 1 => 1211

So here we can observe that while converting number like "1211"
We should get result as => one 1 one 2 two 1's
We can optimise this into writing => one 1 one 2 two 1 (excluded "'s")

We can make this more simpler by directly writing the count(number in words) in number form and the number itself both together like = 21 (for "two 1"), 31 (for three 1)
So 1211 will look like = 111221 (one 1 one 2 two 1)
Another example, 111221 will be = 3122211 (three 1 two 2 one 1)

So in our given problem
if (n == 1) we just return 1;
else we just need to iterate from 2 till n and at every iteration we convert the string s(which is initially = "1") using the above optimisation and return it in the end of the iteration
*/

class Solution
{
    string convert(string &s)
    {
        int count = 0, n = s.length();
        char num = '0';
        string t = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (i > 0 and s[i] == s[i - 1])
            {
                count++;
            }
            else
            {
                if (count)
                    t += to_string(count) + num;

                count = 1;
                num = s[i];
            }
        }
        t += to_string(count) + num;

        return t;
    }

public:
    string countAndSay(int n)
    {
        string s = "1";
        for (int i = 2; i <= n; i++)
        {
            s = convert(s);
        }

        return s;
    }
};

int main()
{

    return 0;
}