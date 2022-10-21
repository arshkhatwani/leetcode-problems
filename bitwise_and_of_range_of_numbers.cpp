#include <bits/stdc++.h>
using namespace std;

/*
We will start from the most significant bit(here all numbers are 32 bits so we start from position 31)

Then we will see the bits present in both numbers left and right at that position

If both the bits are equal and 1 then se set the bit as 1 in the answer also

If both the bits are equal and 0 then we do nothing and move on

If both the bits are unequal then there is no point going further and ew break the loop.

We do the above because we know that 0 & something = 0 and we also know that since the bits at this position are unequal that means the numbers in the range [left, right] will be having bits = 0 (no set bits) at the position/index which are less than the current iteration index. So the AND will come as 0 for the current and upcoming iteration hence we break the loop and return the ans
*/

int rangeBitwiseAnd(int left, int right)
{
    int pos = 31, ans = 0;

    for (int i = pos; i >= 0; i--)
    {
        int mask = 1 << i;

        int setBit1 = (left & mask) > 0;
        int setBit2 = (right & mask) > 0;

        if (setBit1 == setBit2 and setBit1 == 1)
        {
            ans = ans | mask;
        }
        else if (setBit1 != setBit2)
        {
            break;
        }
    }

    return ans;
}

int main()
{

    return 0;
}