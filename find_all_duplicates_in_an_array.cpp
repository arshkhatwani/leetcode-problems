#include <bits/stdc++.h>
using namespace std;

/*
O(n) time and O(n) space approach
we take a hashmap and store values and count them

O(n) time and O(1) space approach
Since the numbers are in range [1,n] we can use the array as a hashmap what we can do is we traverse the given array

For every element we check that if the element at index (index = element-1) is negative or not. If it is then we add it to answer

For every element we make the index(index = element-1) to negative. (for example a[i] = 2 then a[1] = -x where x is the value present at 1)
*/

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &a)
    {
        int n = a.size();
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            int element = abs(a[i]);

            if (a[element - 1] < 0)
                ans.push_back(element);

            a[element - 1] *= (-1);
        }

        return ans;
    }
};

int main()
{

    return 0;
}