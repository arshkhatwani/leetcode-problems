#include <bits/stdc++.h>
using namespace std;

class Solution
{
    vector<string> solve(int idx, string &s, unordered_map<string, int> &dict,
                         unordered_map<int, vector<string>> &dp)
    {
        int n = s.length();

        if (idx == n)
        {
            return {""};
        }

        if (dp.find(idx) != dp.end())
        {
            return dp[idx];
        }

        string cur = "";
        vector<string> ans;

        for (int i = idx; i < n; i++)
        {
            cur += s[i];
            if (dict.find(cur) != dict.end())
            {
                vector<string> temp = solve(i + 1, s, dict, dp);
                for (auto t : temp)
                {
                    if (t != "")
                    {
                        ans.push_back(cur + " " + t);
                    }
                    else
                    {
                        ans.push_back(cur);
                    }
                }
            }
        }

        return dp[idx] = ans;
    }

public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, int> dict;
        unordered_map<int, vector<string>> dp;

        for (auto word : wordDict)
        {
            dict[word] = 1;
        }

        return solve(0, s, dict, dp);
    }
};

int main()
{

    return 0;
}