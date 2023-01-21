#include <bits/stdc++.h>
using namespace std;

/*
At every index we have two choices
- To keep it 1
- To keep it 0

If we decide to keep 1 at a particular index so every index after it will also be kept(or changed to) 1
So if we change it to 1 the flips at that point will be = 1 + count of 0s ahead
And if its already 1 then flips at that point will be = count of 0s ahead

Now for 0 to be at that index we can change the char to 0 and keep a 'carry' variable which will keep track of the flips we have made to change it to 0 i.e 'carry' will only increment when s[i] will be changed to 0 (here s = string, i = index)

We can keep a 'ans' variable to store the minimum of the flips calculated

After the iteration we also compare 'ans' with carry because there can be a case where more 0s are present than 1s so the minimum flips can come from flipping only 1s
*/

class Solution
{
public:
    int minFlipsMonoIncr(string s)
    {
        int n = s.length();
        int flips, ans = INT_MAX, carry = 0, zerosAhead = 0;

        for (auto i : s)
        {
            if (i == '0')
                zerosAhead += 1;
        }

        for (int i = 0; i < n; i++)
        {
            zerosAhead = s[i] == '0' ? zerosAhead - 1 : zerosAhead;
            int setTo1 = s[i] == '0' ? 1 : 0;
            flips = setTo1 + zerosAhead + carry;
            ans = min(ans, flips);
            carry = s[i] == '1' ? carry + 1 : carry;
            s[i] = '0';
        }
        ans = min(ans, carry);

        return ans;
    }
};

int main()
{

    return 0;
}