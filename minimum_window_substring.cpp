#include <bits/stdc++.h>
using namespace std;

/*
Here we keep a sliding window with 2 pointers (say {i, j})
We keep moving 'j' till a substring is achieved that contains all the characters of 't'
If we get a substring, then we start moving 'i' to ensure we get the minimum substring possible

TC: O(m + n) where 'm' and 'n' are lengths of strings 's' and 't'
SC: O(2 * 2 * 26) = O(1) as both uppercase and lowercase letters for both strings will be involved
*/

class Solution
{
    bool isValid(unordered_map<char, int> &mp, unordered_map<char, int> &count)
    {
        for (auto i : mp)
        {
            char ch = i.first;
            int freq = i.second;
            if (count[ch] < freq)
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> mp, count;

        for (char ch : t)
        {
            mp[ch]++;
        }

        int i = 0, j = 0, n = s.length();
        int minLen = INT_MAX;
        vector<int> idx = {};

        while (j < n)
        {
            if (isValid(mp, count))
            {
                if (minLen > j - i)
                {
                    minLen = j - i;
                    idx = {i, j - 1};
                }
                count[s[i]]--;
                i++;
            }
            else
            {
                count[s[j]]++;
                j++;
            }
        }
        while (i < j)
        {
            if (isValid(mp, count) and minLen > j - i)
            {
                minLen = j - i;
                idx = {i, j - 1};
            }
            count[s[i]]--;
            i++;
        }
        if (idx.size() == 2)
            i = idx[0], j = idx[1];
        if (minLen == INT_MAX)
            return "";
        return s.substr(i, j - i + 1);
    }
};

int main()
{

    return 0;
}