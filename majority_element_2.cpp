#include <bits/stdc++.h>
using namespace std;

/*
This problem is same as the Majority Element Problem
Brute and better approaches would be same
The optimal approach would be a slight modification of Boyer Moore's Voting Algorithm
Below is the implementation
*/

class Solution
{
public:
    vector<int> majorityElement(vector<int> &a)
    {
        int n = a.size();
        int count1 = 0, count2 = 0, el1 = -1, el2 = -1;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == el1)
            {
                count1++;
            }
            else if (a[i] == el2)
            {
                count2++;
            }
            else if (count1 == 0)
            {
                el1 = a[i];
                count1 = 1;
            }
            else if (count2 == 0)
            {
                el2 = a[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }

        vector<int> ans;
        count1 = count2 = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == el1)
                count1++;
            else if (a[i] == el2)
                count2++;
        }

        if (count1 > n / 3)
            ans.push_back(el1);
        if (count2 > n / 3)
            ans.push_back(el2);

        return ans;
    }
};

int main()
{

    return 0;
}