#include <bits/stdc++.h>
using namespace std;

/*
My approach

I just wrote all the sorted strings for n = 1, 2 ,3
and found a pattern

for n = 2
total strings would be:
5 + 4 + 3 + 2 + 1 = 15

for n = 3
15 + 10 + 6 + 3 + 1 = 35

we can see that for every n (n > 2), the total strings formed by different vowels are:

starting:
from a = the sum of (n-1) sorted strings = 15

from e = (strings formed by a in above line) - (strings formed by a with length n - 1) = 15 - 5 = 10

from i = (strings formed by e in above line) - (strings formed by e with length n - 1) = 10 - 4 = 6

from o = (strings formed by i in above line) - (strings formed by i with length n - 1) = 6 - 3 = 3

from u = (strings formed by o in above line) - (strings formed by o with length n - 1) 3 = 2 = 1

we can do this from i = 3 to i = n and we can return sum after the iteration
see the code for more understanding
*/

class Solution
{
public:
    int countVowelStrings(int n)
    {
        if (n == 1)
            return 5;
        if (n == 2)
            return 15;

        vector<int> prev = {5, 4, 3, 2, 1};
        vector<int> cur;
        int sum = 15;

        for (int i = 3; i <= n; i++)
        {
            cur = vector<int>(5, 0);
            cur[0] = sum;

            for (int j = 1; j < 5; j++)
            {
                cur[j] = cur[j - 1] - prev[j - 1];
                sum += cur[j];
            }

            prev = cur;
        }

        return sum;
    }
};

int main()
{

    return 0;
}