#include <bits/stdc++.h>
using namespace std;

/*
First we need to sort the words array by string length

Then we have to traverse in words array and we also need to make a hashmap with (string, int) as key value pair

Then for every word 'w' we remove every letter and search that generated string 's' in the map, if we find 's' we store the value for the 'w' as (value of 's' in the map + 1) or 1 (if s is not present in the map)

if(s is present in the map) dp[w] = dp[s] + 1
else dp[w] = 1
where 'dp' is the initialised map

And along the iteration we also keep a track of maximum value achieved so far and we return in the end
*/

bool comp(string &a, string &b)
{
    return a.length() < b.length();
}

class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size(), ans = 0;
        unordered_map<string, int> dp;

        sort(words.begin(), words.end(), comp);

        for (auto a : words)
        {
            for (int i = 0; i < a.length(); i++)
            {
                string s = a.substr(0, i) + a.substr(i + 1, a.length() - 1 - i);

                dp[a] = max(dp[a], dp.find(s) == dp.end() ? 1 : dp[s] + 1);

                ans = max(ans, dp[a]);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}