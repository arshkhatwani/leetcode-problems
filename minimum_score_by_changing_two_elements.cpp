#include <bits/stdc++.h>
using namespace std;

/*
Suppose the array is [1,4,7,8,5]
Sort the array: [1,4,5,7,8]

Now the 'high' will be the difference of first element and last element
And 'low' will be the minimum of the difference between adjacent elements

In order to minimise the score, we can

1. Change the first two elements to the third one, that way the 'low' will get 0 and 'high' will be difference of last element and third element
like, [5,5,5,7,8], low = 0, high = 3


2. Change the last two elements to third last(or to 1st element), that way the 'low' will be 0 and 'high' will be difference of third last element and first element
like, [1,4,5,5/1,5/1], low = 0, high = 4

3. Change first element to same as second element and last element to second last element, that way the 'low' will be 0 and 'high' will be the difference of second element and second last element
like, [4,4,5,7,7], low = 0, high = 3

The minimum score of all 3 cases will be the answer
*/

class Solution
{
public:
    int minimizeSum(vector<int> &a)
    {
        sort(a.begin(), a.end());
        int n = a.size();
        int case1 = a[n - 2] - a[1]; // changing first and last
        int case2 = a[n - 1] - a[2]; // changing first 2
        int case3 = a[n - 3] - a[0]; // changing last 2

        int ans = min(case1, min(case2, case3));

        return ans;
    }
};

int main()
{

    return 0;
}