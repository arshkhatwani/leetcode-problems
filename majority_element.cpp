#include <bits/stdc++.h>
using namespace std;

/*
The brute force would be to take every element and check how many times its occuring and then return it if it occurs more than n/2 times
TC: O(n^2)
SC: O(1)

The better approach would be to use hashmap / frequency array to store the count of elements and return the element occuring more than n/2 times
TC: O(n)
SC: O(n)

The optimal approach would be Boyer Moore's Voting Algorithm
Watch video to understand intuition below is the implementation of the algorithm
TC: O(n)
SC: O(1)
*/

class Solution
{
public:
    int majorityElement(vector<int> &a)
    {
        int n = a.size(), count = 0, el;

        for (int i = 0; i < n; i++)
        {
            if (count == 0)
            {
                el = a[i];
            }

            if (a[i] == el)
            {
                count++;
            }
            else
            {
                count--;
            }
        }

        return el;
    }
};

int main()
{

    return 0;
}