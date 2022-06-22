#include <bits/stdc++.h>
using namespace std;

/*
We can do two operations:
1. Replace "00" with "10"
2. Replace "10" with "01"

No matter how many number of 0s are there and how many 1s are present among them, 2nd operation can be applied and the 1s can be shifted at the end and the 0s can be brought all together
say ex, 0101001 can be transformed by using 2nd operation
=> 0100101
=> 0100011
=> 0010011
=> 0001011
=> 0000111

And now on the consecutive 0s, we can apply the 1st operation and we would convert all the 0s to 1s except the last 0 present. We can apply this on the above example
=> 0000111
=> 1000111
=> 1100111
=> 1110111 => Final ans

First we will count the leading ones and we dont need to do anything with them. Along with this we will also count the number of 0s present.

And in the above iteration we will make every element of string = 1

Now if count0s is > 0 (i.e 0s exists in the given string) then we know that only 1 0 will remain after all operations and that too the last 0 present in the consecutive 0s part as mentioned above.

So we would make s[count1s + count0s - 1] = '0'
we are adding count1s as we dont have to touch the leading 1s
we are adding count0s - 1 because its the last 0 that needs to be left among the consecutive 0s that would be formed after applying 2nd operation
*/

class Solution
{
public:
    string maximumBinaryString(string s)
    {
        int n = s.length();
        int count0 = 0, count1 = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                count0++;
            else if (!count0)
                count1++;

            s[i] = '1';
        }

        if (count0)
            s[count0 + count1 - 1] = '0';

        return s;
    }
};

int main()
{

    return 0;
}