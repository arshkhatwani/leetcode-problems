#include <bits/stdc++.h>
using namespace std;

// Video: https://youtu.be/m18Hntz4go8

// Dynamic Programming / Prefix Sum
class Solution
{
public:
    int trap(vector<int> &a)
    {
        int n = a.size();
        vector<int> left(n), right(n);

        left[0] = a[0], right[n - 1] = a[n - 1];

        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], a[i]);
            right[n - 1 - i] = max(right[n - i], a[n - 1 - i]);
        }

        int area = 0;
        for (int i = 0; i < n; i++)
        {
            area += min(left[i], right[i]) - a[i];
        }

        return area;
    }
};

// Two pointers
class Solution
{
public:
    int trap(vector<int> &a)
    {
        int n = a.size();
        int l = 0, r = n - 1;
        int leftMax = 0, rightMax = 0;
        int area = 0;

        while (l < r)
        {
            if (a[l] <= a[r])
            {
                if (leftMax < a[l])
                    leftMax = a[l];
                else
                    area += leftMax - a[l];
                l++;
            }
            else
            {
                if (rightMax < a[r])
                    rightMax = a[r];
                else
                    area += rightMax - a[r];
                r--;
            }
        }

        return area;
    }
};

int main()
{

    return 0;
}