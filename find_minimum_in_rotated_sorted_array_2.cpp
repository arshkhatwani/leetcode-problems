#include <bits/stdc++.h>
using namespace std;

/*
Video: https://youtu.be/j3187M1P2Xg

MY APPROACH
Here the concept is same as find minimum in rotated sorted array but since there are duplicates we may face test cases like
[10,1,10,10,10], [3,3,1,3] etc.

And we can track of minimum element with a variable

So inorder to tackle these test cases we may need to visit both the parts of the array(i.e [low, mid] and [mid+1, high])

So here we can visit both parts using recursion in this case

Also in find minimum in rotated sorted array we had two conditions which were:
if(a[mid] > a[0]) low = mid+1
else high = mid
Here it was understood since no duplicates were present either a[mid] > a[0] or a[mid] < a[0].
But here duplicates are there so we need to give conditions like
if(a[mid] >= a[0]) low = mid+1
else high = mid

So total 3 conditions would be there in this problem
if (a[mid] == a[low] and a[mid] == a[high])
    recur for both halves
if(a[mid] >= a[0]) (or you can also write this) if (a[mid] >= a[low])
    recur for right half
else
    recur for left half
*/

class Solution
{
public:
    int findMin(vector<int> &a)
    {
        int n = a.size();
        int low = 0, high = n - 1, mid;

        while (low < high)
        {
            mid = low + (high - low) / 2;

            if (a[mid] > a[high])
            {
                low = mid + 1;
            }
            else if (a[mid] < a[high])
            {
                high = mid;
            }
            else
            {
                high--;
            }
        }

        return a[low];
    }
};

class Solution
{
    void findMin(vector<int> &a, int low, int high, int &ans)
    {
        if (low >= high)
        {
            ans = min(ans, a[low]);
            return;
        }

        int mid = low + (high - low) / 2;

        ans = min(ans, a[low]);

        if (a[mid] == a[low] and a[mid] == a[high])
        {
            findMin(a, mid + 1, high, ans);
            findMin(a, low, mid, ans);
            return;
        }

        if (a[mid] >= a[low]) // or if(a[mid] >= a[0])
        {
            findMin(a, mid + 1, high, ans);
        }

        findMin(a, low, mid, ans);
    }

public:
    int findMin(vector<int> &a)
    {
        int n = a.size();
        int low = 0, high = n - 1, mid, ans = INT_MAX;

        findMin(a, low, high, ans);

        return ans;
    }
};

int main()
{

    return 0;
}