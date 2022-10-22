#include <bits/stdc++.h>
using namespace std;

/*
The hamming distance means the number of different corresponding bits in 2 integers

Since we have to calculate the total hamming distance we can iterate for all bit positions (here 0->31 as 32 bit integers are given) and we can use an inner loop to iterate from end to start and count the number of 0 bits and 1 bits at every position

Now during iteration in the array
if the current number has bit 1 at the position we can add the count of 0s to our answer
Else if the current number has bit 0 at the position we can add the count of 1s to our answer
*/

class Solution
{
public:
    int totalHammingDistance(vector<int> &a)
    {
        int n = a.size(), ans = 0;

        for (int pos = 0; pos < 32; pos++)
        {
            int count0s = 0, count1s = 0;

            for (int i = n - 1; i >= 0; i--)
            {
                int setBit = ((1 << pos) & a[i]) > 0;

                if (setBit)
                {
                    ans += count0s;
                    count1s++;
                }
                else
                {
                    ans += count1s;
                    count0s++;
                }
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}