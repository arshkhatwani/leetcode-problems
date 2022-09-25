#include <bits/stdc++.h>
using namespace std;

/*
Since we are required to concatenate binary strings and return the integer conversion of it

We can have a 'sum' variable set to 0 and we can iterate from 1 to n (assume i = iterator)
And we can calculate the length of binary form of i and shift our current sum by i bits and then add i to our sum

We'll be taking MOD after shift and after adding i to avoid overflow

The sum will be our answer
*/

class Solution
{
public:
    int concatenatedBinary(int n)
    {
        long long sum = 0, MOD = 1e9 + 7;

        for (int i = 1; i <= n; i++)
        {
            long long shift = log2(i) + 1;
            sum = sum << shift;
            sum %= MOD;

            sum = (sum + i) % MOD;
        }

        return sum;
    }
};

int main()
{

    return 0;
}