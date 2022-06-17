#include <bits/stdc++.h>
using namespace std;

/*
This is GAP Theorem (no intuition, just algo)
You take the total size of both arrays and divide it by 2, let that value be 'mid' and you merge the array as it is
and you place two pointers i,j at start and at the divided value and you compare the values of a[i], a[j] if(a[i] > a[j]) swap(a[i], a[j])
and we increment i and j and incase j goes out of the array we calculate the new value by dividing mid by 2 and we continue this process till mid becomes 0

Remember if we mid is an odd number and we divide it by 2 then we take the rounded off/ceil value
*/

class Solution
{
private:
    int getMid(int mid)
    {
        if (mid == 1)
            return 0;
        if (mid % 2 == 1)
        {
            mid++;
        }
        return mid / 2;
    }

public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        if (n == 0)
            return;

        for (int i = 0; i < n; i++)
        {
            nums1[m + i] = nums2[i];
        }
        if (m == 0)
            return;

        int mid = getMid(m + n), i, j;
        i = 0;
        j = mid;

        while (mid)
        {
            if (nums1[i] > nums1[j])
            {
                swap(nums1[i], nums1[j]);
            }
            i++;
            j++;
            if (j == nums1.size())
            {
                mid = getMid(mid);
                i = 0;
                j = mid;
            }
        }
    }
};

int main()
{

    return 0;
}