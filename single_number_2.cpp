#include <bits/stdc++.h>
using namespace std;

/*
Count bits at every position(0 to 31)

The bits which are in form 3N i.e the count of those bits are divisible by 3 then we know that those bits cannot belong to our unique number

The bits which are in the form 3N + 1 i.e modulo/remainder of the count when divided by 3 is 1 then we know that there is a set bit at that position in our answer so we set the bit at that position in our answer (initially we take answer = 0)

See the code to understand more
*/

class Solution
{
public:
    int singleNumber(vector<int> &a)
    {
        int n = a.size();
        unsigned int shift = 1, ans = 0;

        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            for (int num : a)
            {
                if ((num & shift) > 0)
                    count++;
            }

            count %= 3;
            ans += count * shift;
            shift <<= 1;
        }

        return ans;
    }
};

int main()
{

    return 0;
}