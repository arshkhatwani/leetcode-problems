#include <bits/stdc++.h>
using namespace std;

/*
We can use an array to store the last occured position of every element in the string
This last position will help us determining the limit till we have to extend the current partition

See the code to understand more
*/

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int n = s.length(), first = 0, last = 0;
        vector<int> ans, stored(26, -1);

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];
            stored[ch - 'a'] = i;
        }

        for (int i = 0; i <= n; i++)
        {
            if (i == n or i > last)
            {
                ans.push_back(last - first + 1);
                first = last = i;
            }

            if (i < n and i <= last)
            {
                char ch = s[i];
                last = max(last, stored[ch - 'a']);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}