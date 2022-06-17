#include <bits/stdc++.h>
using namespace std;

// The idea is we will loose if we get 4, and we will win if we give 4 to our opponent and by backtesting it is happening with every multiple of 4

bool canWinNim(int n)
{
    if (n % 4 == 0)
        return false;
    return true;
}

int main()
{

    return 0;
}