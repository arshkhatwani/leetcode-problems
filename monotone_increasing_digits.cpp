#include <bits/stdc++.h>
using namespace std;

/*
Greedy Approach
Keep a variable 'k' this will be used to set some digits to '9'
Iterate from right
If current digit >= digit on left => continue
Else reduce digit on left by 1 and set k = current iteration index

After the iteration is complete iterate from k to the end of the number (k to right end) and make all digits equal to 9
*/

class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string num = to_string(n);
        int size = num.length(), k = size;

        for (int i = size - 1; i >= 1; i--)
        {
            if (num[i] >= num[i - 1])
                continue;

            num[i - 1] = num[i - 1] - 1;
            k = i;
        }

        for (int i = k; i < size; i++)
        {
            num[i] = '9';
        }

        return stoi(num);
    }
};

int main()
{

    return 0;
}