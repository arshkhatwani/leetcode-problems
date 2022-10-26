#include <bits/stdc++.h>
using namespace std;

/*
This problem is same as the Travelling Salesman Problem

Here we know that no string in 'words' is a substring of another string in 'words'

But there can be common substrings which are ending subtring for one and starting substring of another element in words

So we can take an adjacency matrix a[][] where,
a[i][j] = index(let assume it as 'idx') from where we need to append the jth string after ith string
This is because the subtring(from 0 to idx-1) in jth string is common substring between ith string and jth string

For example take ith string = "gcta"
            take jth string = "ctaagt"

Here the common substring is = "cta" which is ending substring for ith one and starting substring for jth one
Hence here a[i][j] = 3

Then after making this matrix we can apply the TSP logic here and we can keep a bitmask to keep track of nodes/strings visited and we can have a 2d array of strings to store answers as per index and bitmask for DP.

For reference
https://leetcode.com/problems/find-the-shortest-superstring/discuss/2433964/C%2B%2B-or-DP-%2B-Graph-%2B-BitMask-with-comments-for-understanding
*/

class Solution
{
    vector<vector<string>> dp;
    vector<vector<int>> makeMatrix(vector<string> &words)
    {
        int size = words.size();
        vector<vector<int>> a(size, vector<int>(size, 0));

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (i == j)
                {
                    a[i][j] = -1;
                    continue;
                }

                int m = words[i].length(), n = words[j].length();
                string s1 = words[i], s2 = words[j];

                for (int k = 0; k < m; k++)
                {
                    int p = k, q = k;

                    while (p < m and s1[p] == s2[p - q])
                    {
                        p++;
                    }

                    if (p == m)
                    {
                        a[i][j] = p - q;
                        break;
                    }
                }
            }
        }

        return a;
    }

    string solve(vector<string> &words, vector<vector<int>> &a, int idx, int bitmask)
    {
        int n = words.size();
        if (bitmask == ((1 << n) - 1))
            return "";

        string ans = "";

        if (dp[idx][bitmask] != "")
            return dp[idx][bitmask];

        for (int i = 0; i < n; i++)
        {
            if (i == idx)
                continue;
            if ((bitmask & (1 << i)) > 0)
                continue;

            int newMask = bitmask | (1 << i);
            string subProb = words[i].substr(a[idx][i]) + solve(words, a, i, newMask);
            if (ans == "")
                ans = subProb;
            else if (ans.length() > subProb.length())
            {
                ans = subProb;
            }
        }

        return dp[idx][bitmask] = ans;
    }

public:
    string shortestSuperstring(vector<string> &words)
    {
        int n = words.size();
        vector<vector<int>> a = makeMatrix(words);
        dp = vector<vector<string>>(n, vector<string>(1 << n, ""));

        string ans = "";

        for (int i = 0; i < n; i++)
        {
            int bitmask = 1 << i;
            string subProb = words[i] + solve(words, a, i, bitmask);

            if (ans == "")
                ans = subProb;
            else if (ans.length() > subProb.length())
                ans = subProb;
        }

        return ans;
    }
};

int main()
{

    return 0;
}