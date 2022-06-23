#include <bits/stdc++.h>
using namespace std;

/*
GREEDY APPROACH

We can first iterate the string and count all the 0s and add it to our ans

Then we can keep a variable 'total' initialised to 0 and iterate from the back

While iterating as we get a 1 at some index i we check if adding that number(1 left shifted till i-1) makes 'total' <= k or not

If yes, then we add it to 'total' and proceed the iteration
else, we break the loop as there is no point iterating further because if this number makes our 'total' greater than k, then further numbers would obviously do the same because they are greater than the number formed at current iteration

Since we are dealing with integers here, we can only left shift till 31 places any places greater than that would result in integer overflow and obviously they would form numbers greater than k.
So to do this we would only iterate till (31 chars in the string OR complete string)(whichever is smaller) in right to left direction

See the code to understand more

Watc video to understand intuition (video's code might be different): https://youtu.be/_Mitj9TfHk0
*/

class Solution
{
public:
    int longestSubsequence(string s, int k)
    {
        int n = s.length(), ans = 0, total = 0;

        for (auto i : s)
        {
            if (i == '0')
                ans++;
        }

        for (int i = n - 1; i >= max(0, n - 31); i--)
        {
            if (s[i] == '0')
                continue;

            int num = 1 << n - 1 - i;
            if (s[i] == '1' and total + num <= k)
            {
                total += num;
                ans++;
            }
            else
                break;
        }

        return ans;
    }
};

int main()
{

    return 0;
}