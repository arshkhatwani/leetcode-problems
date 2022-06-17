#include <bits/stdc++.h>
using namespace std;

/*
We store the count of all elements in descending order in a map
Then for every element in map:
    We add it in ans string till the limit reaches repeatLimit and then we add the character less than it once and reset the limit to 0.
    We do this till there is no count left of element.
*/

string repeatLimitedString(string s, int repeatLimit)
{
    map<char, int, greater<int>> count;
    int limit;
    string ans = "";

    for (auto i : s)
    {
        if (count.find(i) == count.end())
        {
            count.insert({i, 1});
        }
        else
        {
            count[i]++;
        }
    }

    for (auto i = count.begin(); i != count.end(); i++)
    {
        if (i->second == 0)
            continue;

        limit = 0;

        while (limit != repeatLimit and i->second)
        {
            ans += i->first;
            i->second--;
            limit++;

            if (limit == repeatLimit and i->second)
            {
                auto k = i;
                k++;
                while (k->second == 0 and k != count.end())
                    k++;
                if (k != count.end())
                {
                    ans += k->first;
                    k->second--;
                    limit = 0;
                }
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}