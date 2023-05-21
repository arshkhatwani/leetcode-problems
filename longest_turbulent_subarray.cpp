#include <bits/stdc++.h>
using namespace std;

/*
Single pass solution
So lets say we take an array like [9,4,2,10,7,8,8].
The comparison will be like [1, 1, -1, 1, -1, 1] such that a[i] > a[i+1] = 1, a[i] < a[i+1] = -1 and a[i] == a[i-1] = 0
So in the comparison the blocks will get formed like this [[1], [1, -1, 1, -1, 1]]
So we just need to get the longest block
Refer LC editorial to understand in detail

Two pass solution
There are two types of conditions and we can check for both of them using sliding window 2 times
One for first condition
Two for second condition
*/

// Single pass solution
class Solution
{
    int compare(int a, int b)
    {
        if (a == b)
            return 0;
        if (a < b)
            return -1;
        return 1;
    }

public:
    int maxTurbulenceSize(vector<int> &a)
    {
        int n = a.size(), maxLen = 1;
        int i = 0, j = 1;

        while (j < n)
        {
            int c = compare(a[j - 1], a[j]);
            if (c == 0)
            {
                i = j;
            }
            else if (j == n - 1 or c * compare(a[j], a[j + 1]) != -1)
            {
                maxLen = max(maxLen, j - i + 1);
                i = j;
            }
            j++;
        }

        return maxLen;
    }
};

// Two pass solution
class Solution
{
public:
    int maxTurbulenceSize(vector<int> &a)
    {
        int n = a.size(), maxLen = 1;
        int i = 0, j = 0;

        while (j < n - 1)
        {
            if (j % 2 and a[j] <= a[j + 1])
            {
                i = j + 1;
            }
            else if (j % 2 == 0 and a[j] >= a[j + 1])
            {
                i = j + 1;
            }
            j++;
            maxLen = max(maxLen, j - i + 1);
        }

        i = 0;
        j = 0;
        while (j < n - 1)
        {
            if (j % 2 and a[j] >= a[j + 1])
            {
                i = j + 1;
            }
            else if (j % 2 == 0 and a[j] <= a[j + 1])
            {
                i = j + 1;
            }
            j++;
            maxLen = max(maxLen, j - i + 1);
        }

        return maxLen;
    }
};

int main()
{

    return 0;
}