#include <bits/stdc++.h>
using namespace std;

/*
First we need to split string as per '.' character and then what we can do is store the split strings as integers instead of strings while converting

Then we can take a pointer and run in it till maximum length among both the strings and keep comparing till one number comes as as bigger if no one comes as bigger we just return 0 at the end

Now incase one of the arrays is completed we will take 0 for comparison(see the code to understand more)
TC: O(m + n)
SC: O(m + n)

Here we can optimise this and reduce our space complexity to O(1) by just iterating both the strings and converting the digits between '.' to numbers while iteration (see second code to understand more)
Now,
TC: O(m + n)
SC: O(1)
*/

class Solution
{
    vector<int> split(string s)
    {
        vector<int> a;
        string t = "";

        for (auto i : s)
        {
            if (i == '.')
            {
                a.push_back(stoi(t));
                t = "";
                continue;
            }

            t += i;
        }
        a.push_back(stoi(t));

        return a;
    }

public:
    int compareVersion(string version1, string version2)
    {
        vector<int> v1 = split(version1), v2 = split(version2);
        int m = v1.size(), n = v2.size();

        int maxLen = max(m, n), i = 0;

        for (i = 0; i < maxLen; i++)
        {
            int c1 = i < m ? v1[i] : 0;
            int c2 = i < n ? v2[i] : 0;

            if (c1 > c2)
                return 1;
            if (c1 < c2)
                return -1;
        }

        return 0;
    }
};

class Solution
{
public:
    int compareVersion(string s1, string s2)
    {
        int m = s1.length(), n = s2.length();
        int v1 = 0, v2 = 0, i = 0, j = 0;

        while (i < m or j < n)
        {
            while (i < m and s1[i] != '.')
            {
                v1 = (v1 * 10) + (s1[i] - '0');
                i++;
            }

            while (j < n and s2[j] != '.')
            {
                v2 = (v2 * 10) + (s2[j] - '0');
                j++;
            }

            if (v1 < v2)
                return -1;
            if (v1 > v2)
                return 1;

            v1 = 0, v2 = 0;
            i++, j++;
        }

        return 0;
    }
};

int main()
{

    return 0;
}