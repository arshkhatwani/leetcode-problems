#include <bits/stdc++.h>
using namespace std;

/*
A number 'n' is a power of 4 if:
1. It's greater than 0
2. It's power of 2
3. n-1 is divisible by 3
*/

bool isPowerOfFour(int n)
{
    return n > 0 and (n & (n - 1)) == 0 and (n - 1) % 3 == 0;
}

int main()
{
    int n;
    cin >> n;

    cout << isPowerOfFour(n);

    return 0;
}