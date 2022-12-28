#include <bits/stdc++.h>
using namespace std;

/*
This problem is about finding pattern

For n = 1, ans = 1
For n = 2, ans = 2
For n = 3, ans = 5
Let the above be the base cases

For n = 4, ans = 11
For n = 5, ans = 24
For n = 6, ans = 53

We can observe that a[n] = 2 * a[n-1] + a[n-3]
*/

class Solution
{
public:
    int numTilings(int n)
    {
        vector<long long> a(max(n + 1, 4), 0);
        long long MOD = 1e9 + 7;
        a[0] = 0;
        a[1] = 1;
        a[2] = 2;
        a[3] = 5;
        for (int i = 4; i <= n; i++)
        {
            a[i] = 2 * a[i - 1] + a[i - 3];
            a[i] %= MOD;
        }
        return a[n];
    }
};

// Space optimised
class Solution
{
public:
    int numTilings(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;
        long long x = 5, y = 2, z = 1;
        long long MOD = 1e9 + 7;

        for (int i = 4; i <= n; i++)
        {
            long long newVal = 2 * x + z;
            newVal %= MOD;
            z = y;
            y = x;
            x = newVal;
        }
        return x;
    }
};

int main()
{

    return 0;
}