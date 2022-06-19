#include <bits/stdc++.h>
using namespace std;

/*
Here we need to store the remainders of the prefix sum in the map and if we encounter same remainder again then we know that there exists a subarray whose sum must have been divisible by k

Now while storing remainders we can also encounter negative array elements so instead of storing their negative remainders we conver them into positive ones and store them

default way of storing remainder = sum % k
we will store like this = (sum % k + k) % k

Watch video to understand the math in detail: https://youtu.be/QM0klnvTQzk

And for handling the case where prefixSum % k == 0 (prefixSum divisible by k) we already store 0 with val 1 in the map. This saves us from writing
if(sum % k == 0) count++;
this above line in our iteration, I have added this line in my prev leetcode solutions of this problem
*/

class Solution
{
public:
    int subarraysDivByK(vector<int> &a, int k)
    {
        unordered_map<int, int> mp;
        int sum = 0, count = 0;
        mp[0]++;

        for (auto i : a)
        {
            sum += i;

            int x = sum % k;
            x = (x + k) % k;

            if (mp[x])
                count += mp[x];

            mp[x]++;
        }

        return count;
    }
};

int main()
{

    return 0;
}