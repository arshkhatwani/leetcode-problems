#include <bits/stdc++.h>
using namespace std;

/*
We keep an array of lengths with intially set all values to 1

We keep an unordered map to keep track of all the indices of the traversed element

We traverse from back (right to left) and for very element
    - We calculate the next possible element i.e lets say element is a[i] then we calculate a[i] + diff
    - Then we try to find the index of that element in the map
    - If we find the element(say its found index is 'i') then we take the value at that 'i' in array of lengths and add 1 to it and store it in the current index in array of lengths
    - This helps us keep track of the length arithmetic sequence obtained for every element
    - We record the element and its index as key,val pair in map

We keep track of the maximum length calculated so far and return it as answer
*/

class Solution
{
public:
    int longestSubsequence(vector<int> &a, int diff)
    {
        int n = a.size(), ans = 1;
        unordered_map<int, int> mp;
        vector<int> len(n, 1);
        mp[a[n - 1]] = n - 1;

        for (int i = n - 2; i >= 0; i--)
        {
            int el = a[i] + diff;

            if (mp.find(el) != mp.end())
            {
                int idx = mp[el];
                len[i] += len[idx];
            }
            mp[a[i]] = i;
            ans = max(ans, len[i]);
        }

        return ans;
    }
};

int main()
{

    return 0;
}