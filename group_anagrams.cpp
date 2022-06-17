#include <bits/stdc++.h>
using namespace std;

/*
INTUITION: anagrams look same after sorting so every anagram can be stored in a vector which is present as value to their sorted form as string in a hashmap

The idea is to sort string at every iteration and store a vector <string> against it as key-val pair in hashmap and we add the current iteration string to the vector

Now since the string consists of only smallcase letters we can use count sort to reduce some time complexity
*/

class Solution
{
private:
    string countSort(string &s)
    {
        vector<int> c(26, 0);

        for (auto i : s)
        {
            c[i - 'a']++;
        }

        string newS = "";
        for (int i = 0; i < 26; i++)
        {
            newS += string(c[i], i + 'a');
        }

        return newS;
    }

public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;

        int n = strs.size();

        for (int i = 0; i < n; i++)
        {
            string s = strs[i];

            // sort(s.begin(), s.end()); // this could also be used
            s = countSort(s);

            mp[s].push_back(strs[i]);
        }

        vector<vector<string>> ans;
        for (auto i : mp)
        {
            ans.push_back(i.second);
        }

        return ans;
    }
};

int main()
{

    return 0;
}