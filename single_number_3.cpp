#include <bits/stdc++.h>
using namespace std;

/*
Calculate cumulative xor of the array

Find the position of first set bit in the cumulative xor

Then all the numbers with set bit on that pos xor them to one set(setA) and other numbers to the other set(setB)

setA and setB are the two unique numbers
*/

class Solution
{
public:
    vector<int> singleNumber(vector<int> &a)
    {
        int n = a.size();
        int cumuXor = 0;

        for (int i = 0; i < n; i++)
        {
            cumuXor ^= a[i];
        }

        int pos = 0;
        while ((cumuXor & 1) == 0)
        {
            cumuXor >>= 1;
            pos++;
        }

        int setA = 0, setB = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] & (1 << pos))
                setA ^= a[i];
            else
                setB ^= a[i];
        }

        return {setA, setB};
    }
};

int main()
{

    return 0;
}