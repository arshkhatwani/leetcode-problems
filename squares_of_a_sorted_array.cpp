#include <bits/stdc++.h>
using namespace std;

/*
Brute force:
Just do the squares of all elements and then sort the array
TC: O(nlog(n))
SC: O(1)

Optimised:
Take 2 pointers i, j at index 0 and n-1

Take another pointer k = n - 1 which would point the result array

Compare abs(a[i]) and abs(a[j]) or compare a[i]*a[i] and a[j]*a[j] whatever is bigger place it at the end of result array and decrement k

Increment i if a[i] was bigger or decrement j if a[j] was bigger

Repeat till the array gets filled
TC: O(n)
SC: O(n)
*/

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &a)
    {
        vector<int> ans(a.size(), 0);
        int i = 0;
        int j = a.size() - 1;

        for (int k = a.size() - 1; k >= 0; k--)
        {
            if (abs(a[i]) > abs(a[j]))
            {
                ans[k] = a[i] * a[i];
                i++;
            }
            else
            {
                ans[k] = a[j] * a[j];
                j--;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}