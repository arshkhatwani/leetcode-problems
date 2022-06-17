#include <bits/stdc++.h>
using namespace std;

// Approach https://youtu.be/XFh_AoEdOTw

bool checkInclusion(string s1, string s2)
{
    if (s1.length() > s2.length())
    {
        return false;
    }

    vector<int> a(26, 0);
    vector<int> b(26, 0);

    for (int i = 0; i < s1.length(); i++)
    {
        a[s1[i] - 'a']++;
        b[s2[i] - 'a']++;
    }

    int l = 0, r = s1.length() - 1;
    while (r < s2.length())
    {
        if (a == b)
            return true;

        r++;
        if (r != s2.length())
            b[s2[r] - 'a']++;
        b[s2[l] - 'a']--;
        l++;
    }

    return false;
}

int main()
{

    return 0;
}