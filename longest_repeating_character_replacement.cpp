#include <bits/stdc++.h>
using namespace std;

// Logic: https://youtu.be/gqXU1UyA8pk?si=dxgi2hgNbley4ukj

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int n = s.length(), ans = 0;
        vector<int> count(26, 0);
        int i = 0, j = 0, maxFreq = 0;
        count[s[0] - 'A'] = 1;

        while (j < n)
        {
            int len = j - i + 1;
            maxFreq = max(maxFreq, count[s[j] - 'A']);

            if (len - maxFreq <= k)
            {
                ans = max(len, ans);
                j++;
                if (j < n)
                {
                    count[s[j] - 'A'] += 1;
                }
            }
            else
            {
                count[s[i] - 'A'] -= 1;
                i++;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}