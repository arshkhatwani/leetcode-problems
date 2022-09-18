#include <bits/stdc++.h>
using namespace std;

/*
Take an empty array to store candies for each child
Iterate from left to right and if a[i] > a[i-1] and c[i] <= c[i-1] set c[i] = c[i-1] + 1
Iterate from right to left and if a[i] > a[i+1] and c[i] <= c[i+1] set c[i] = c[i+1] + 1
Take sum of candies array and return it as answer

Video link: https://youtu.be/Ouvvw6R4pyk
*/

class Solution
{
public:
    int candy(vector<int> &a)
    {
        int n = a.size(), ans = 0;
        vector<int> c(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (a[i] > a[i - 1] and c[i] <= c[i - 1])
            {
                c[i] = c[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] > a[i + 1] and c[i] <= c[i + 1])
            {
                c[i] = c[i + 1] + 1;
            }
        }

        for (auto i : c)
            ans += i;

        return ans;
    }
};

int main()
{

    return 0;
}