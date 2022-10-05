#include <bits/stdc++.h>
using namespace std;

/*
We can solve this problem using bit manipulation and greddy approach

if setBits(n1) == setBits(n2) return n1 as 'ans'

if setBits(n1) < setBits(n2) (let m = setBits(n2) - setBits(n1))
    -> Then pick n1 as your 'ans' and iterate from right to left in binary form of n1 and where there is no setBit(i.e bit == 0) set bit at that pos to 1 in 'ans'
    -> Do this for m bits only

    Because we need the minimal xor so we start setting bits to 1 from end i.e right to left

if setBits(n1) > setBits(n2) (let m = setBits(n2))
    -> Take 'ans' as 0 and iterate from left to right in binary form of n1 and set bits to 1 where you see a 0 bit
    -> Do this for m bits only

    Because we need the minimal xor and we cannot take ans = n1 here because n1 has more bits so for the first m set bits from left to right we set bits to 1 at those positions in our answer and that would give us the minimal xor
*/

class Solution
{
public:
    int minimizeXor(int num1, int num2)
    {
        int setBitsN1 = __builtin_popcount(num1);
        int setBitsN2 = __builtin_popcount(num2);

        if (setBitsN1 == setBitsN2)
            return num1;

        int ans = 0;

        if (setBitsN1 > setBitsN2)
        {
            int count = setBitsN2;

            for (int i = 31; i >= 0 and count; i--)
            {
                if ((num1 & 1 << i) > 0)
                {
                    ans = ans | 1 << i;
                    count--;
                }
            }
        }
        else if (setBitsN1 < setBitsN2)
        {
            ans = num1;
            int count = setBitsN2 - setBitsN1;

            for (int i = 0; i < 32 and count; i++)
            {
                if ((num1 & (1 << i)) == 0)
                {
                    ans = ans | 1 << i;
                    count--;
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