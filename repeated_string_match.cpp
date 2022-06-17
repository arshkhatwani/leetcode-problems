#include <bits/stdc++.h>
using namespace std;

/*
We have to apply rabin karp algo to check both the strings

The Naive String Matching algorithm slides the pattern one by one. After each slide, it one by one checks characters at the current shift and if all characters match then prints the match.
Like the Naive Algorithm, Rabin-Karp algorithm also slides the pattern one by one. But unlike the Naive algorithm, Rabin Karp algorithm matches the hash value of the pattern with the hash value of current substring of text, and if the hash values match then only it starts matching individual characters.
Read more at gfg: https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/

So here we apply this algo while checking

First we keep on adding string 'a' to itself till its length gets >= b's length and we keep a track of count to know how many times 'a' has been added to itself

Now after loop we check if a == b, if yes we return count
if no, then we match a and b once and if it does match we return count
if no, we again add 'a' to itself for one last time and then match if it matches we return count + 1 as answer (as 'a' has been added one more time)
if nothing matches till now we return -1
*/

class Solution
{
    bool match(string a, string &b, unordered_map<char, int> &mp1)
    {
        unordered_map<char, int> mp2;
        int m = a.length(), n = b.length();

        for (int i = 0; i < n; i++)
        {
            mp2[a[i]]++;
        }

        int i = 0, j = n - 1;
        while (j < m)
        {
            if (mp1 == mp2)
            {
                string s = a.substr(i, n);
                if (s == b)
                    return true;
            }

            mp2[a[i]]--;
            if (mp2[a[i]] == 0)
                mp2.erase(a[i]);

            i++, j++;
            if (j < m)
                mp2[a[j]]++;
        }

        return false;
    }

public:
    int repeatedStringMatch(string a, string b)
    {
        if (a == b)
            return 1;
        int ans = 1;
        string src = a;

        unordered_map<char, int> mp1;
        for (auto i : b)
        {
            mp1[i]++;
        }

        while (src.length() < b.length())
        {
            src += a;
            ans++;
        }

        if (src == b)
            return ans;
        if (match(src, b, mp1))
            return ans;
        if (match(src + a, b, mp1))
            return ans + 1;

        return -1;
    }
};

int main()
{

    return 0;
}