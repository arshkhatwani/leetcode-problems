#include <bits/stdc++.h>
using namespace std;

/*
We would need to count the number of substrings a character appears in FOR every character in the string.
And the character appears in the string should appear only once.

For example, if the string is "abcaxy", then the number of substrings that 'a' (index 3) appears in is .
It is calculated by:
Number of left chars till start or before another 'a' comes = 2 (b, c)
Number of right chars till end or after another 'a' comes = 2 (x, y)
Self string of length 1 formed by the character (i.e. string will be "a") = 1
Total subtrings formed by 'a' = left + right + (left * right) + 1
Total subtrings formed by 'a' = 2 + 2 + (2 * 2) + 1 = 4 + 4 + 1 = 9

So we need to calculate this count for every char and add it to our result

TC = O(3*n) = O(n)
SC = O(2*n) = O(n)
*/

class Solution
{
public:
    int uniqueLetterString(string s)
    {
        int n = s.length(), total = 0;
        vector<vector<int>> left(n), right(n);

        left[0] = vector<int>(26, -1);
        right[n - 1] = vector<int>(26, n);

        // Calculating left side
        for (int i = 1; i < n; i++)
        {
            vector<int> chars = left[i - 1];
            int ch = s[i - 1] - 'A';
            chars[ch] = i - 1;
            left[i] = chars;
        }

        // Calculating right side
        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> chars = right[i + 1];
            int ch = s[i + 1] - 'A';
            chars[ch] = i + 1;
            right[i] = chars;
        }

        for (int i = 0; i < n; i++)
        {
            int ch = s[i] - 'A';
            int leftStr = i - left[i][ch] - 1;
            int rightStr = right[i][ch] - i - 1;
            int self = 1;

            total += (leftStr + rightStr + leftStr * rightStr + self);
        }

        return total;
    }
};

int main()
{

    return 0;
}