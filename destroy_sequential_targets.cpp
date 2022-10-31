#include <bits/stdc++.h>
using namespace std;

/*
INTUITION
The elements with same remainder module by space, can be destroyed together.

We can sort the array in descending order

We can keep track of modulo of every element with 'space'

And for every element the number of targets it can destroy is all the numbers greater than that element with same modulo as that element
*/

class Solution
{
public:
    int destroyTargets(vector<int> &a, int space)
    {
        sort(a.begin(), a.end(), greater<int>());
        unordered_map<int, int> count;
        int n = a.size();
        int maxTargets = 0, ans = a[n - 1];

        for (int i = 0; i < n; i++)
        {
            int r = a[i] % space;
            int targets = count[r];

            if (maxTargets < targets)
            {
                maxTargets = targets;
            }

            if (maxTargets == targets)
            {
                ans = a[i];
            }

            count[r]++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}