#include <bits/stdc++.h>
using namespace std;

/*
Refer: https://leetcode.com/problems/check-if-point-is-reachable/solutions/3082680/greedy-vs-gcd/
*/

class Solution
{
public:
    bool isReachable(int x, int y)
    {
        if (x == 1 and y == 1)
            return true;

        if (x % 2 == 0)
            return isReachable(x / 2, y);

        if (y % 2 == 0)
            return isReachable(x, y / 2);

        if (x < y)
            return isReachable(x, y - x);

        if (x > y)
            return isReachable(x - y, y);

        return false;
    }
};

int main()
{

    return 0;
}