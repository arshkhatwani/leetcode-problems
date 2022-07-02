#include <bits/stdc++.h>
using namespace std;

/*
For every x in array we need to find a y such that:
y > 0.5*x + 7 AND
y <= x AND
(x >= 100 or y <= 100) this condition would always be true due to above 2 conditions so we would only consider the above 2 conditions and won't consider the 3rd one

Now to do this we would sort the array first and for every 'x' in the array:
We want the count of all 'y'(s) who are > 0.5*x + 7 AND <= x
So let lowerVal = 0.5*x + 7, upperVal = x
Now we want the index of first element present in the array greater than lowerVal and we want the last occurence of the upperVal in the array
So to get the index related to lowerVal we would use upper bound and to get the index related to upperVal we would use lower bound + a while loop to increment the index we got from lower bound to the last position where upperVal is present

Then we would calculate the number of requests made by x to y = upperIdx - lowerIdx + 1
Now there's a chance that in the range (lowerIdx, upperIdx) our x's idx can also lie and x cannot make a request to itself so if this condition is true we would decrement our requests by 1

We would store all the requests for a particular x in the map and during iteration if x is repeated(which means it would already be present in the map) we would simply add the map's value instead of doing the binary search again
*/

class Solution
{
public:
    int numFriendRequests(vector<int> &a)
    {
        sort(a.begin(), a.end());

        int count = 0, n = a.size();
        int lowerIdx, upperIdx;

        unordered_map<int, int> store;

        for (int i = 0; i < n; i++)
        {
            if (store.find(a[i]) != store.end())
            {
                count += store[a[i]];
                continue;
            }

            int lowerVal = a[i] / 2 + 7;
            int upperVal = a[i];

            lowerIdx = upper_bound(a.begin(), a.end(), lowerVal) - a.begin();
            upperIdx = lower_bound(a.begin(), a.end(), upperVal) - a.begin();

            while (upperIdx + 1 < n and a[upperIdx + 1] == upperVal)
                upperIdx++;

            int requests = max(0, upperIdx - lowerIdx + 1);

            if (lowerIdx <= i and upperIdx >= i)
                requests--;

            store[a[i]] = requests;
            count += requests;
        }

        return count;
    }
};

int main()
{

    return 0;
}