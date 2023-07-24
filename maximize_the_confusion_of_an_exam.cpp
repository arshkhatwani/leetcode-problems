#include <bits/stdc++.h>
using namespace std;

/*
We can use sliding window to solve this problem we can keep increasing the window and keep a count of both 'T' and 'F' and we keep on counting the answer as long as min(countF, countT) <= k

Incase min(countF, countT) > k then we decrease the size of window from left side to make it valid again

The main difference between normal and advance sliding window is we are decreasing the length of sliding window in normal one which we do not in advance on because we are trying to calculate maximum valid length so instead of decreasing it and then increasing it again later we directly move the entire sliding window keeping its length same once it gets invalid

See the LC Editorial to understand in detail
*/

// Advanced Sliding Window
class Solution
{
public:
    int maxConsecutiveAnswers(string s, int k)
    {
        int n = s.length(), maxLen = 0;
        int countT = 0, countF = 0;

        for (int i = 0; i < n; i++)
        {
            countT += (s[i] == 'T');
            countF += (s[i] == 'F');

            int mini = min(countT, countF);

            if (mini <= k)
            {
                maxLen++;
            }
            else
            {
                countT -= (s[i - maxLen] == 'T');
                countF -= (s[i - maxLen] == 'F');
            }
        }

        return maxLen;
    }
};

// Normal Sliding Window
class Solution
{
public:
    int maxConsecutiveAnswers(string s, int k)
    {
        int n = s.length(), maxLen = 0;
        int i = 0, j = 0, countT = 0, countF = 0;

        while (j < n)
        {
            countT += (s[j] == 'T');
            countF += (s[j] == 'F');

            while (min(countT, countF) > k)
            {
                countT -= (s[i] == 'T');
                countF -= (s[i] == 'F');

                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};

int main()
{

    return 0;
}