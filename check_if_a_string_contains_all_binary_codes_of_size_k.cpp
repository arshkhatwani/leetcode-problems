#include <bits/stdc++.h>
using namespace std;

/*
For getting the total number binary codes/strings of size k, we can see that the smallest string would be "000"(say k = 3) and the largest string would be "111". So what we observe here is that the total numbers would be 2^k (here 2^3 = 8)

Now the naive approach would be to generate all the substrings of length k while traversing and store every string in a map and at the end we need to check if the count of the map is == 2^k or not
TC: O(n*k)
SC: O(k)


The optimal approach would be to use bit manipulation to get strings and store their decimal forms in map

Suppose s="11010110" and k = 3,
Now first we would see x="110" and in the next iteration we want "101"

So in order to achieve this, we would first shift our current string(x) 1 positon left i.e x << 1 which would give us "1100"
Now we need to remove the leftmost bit so what we can do is AND operation between x and "0111" this would remove the leftmost bit and "0111" = "111" = 2^k - 1
So our operation would now look like (x << 1) & 2^k

And then we would have to add the bit in the rightmost place which will be done by using OR operation with the current iterating element
So our operation will finally look like ((x << 1) & 2^k) | s[i]

And we would store these decimal forms(hashes) in a map and check if the count of the keys in map is == 2^k or not

TC: O(n)
SC: O(k)
*/

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        int topNum = pow(2, k) - 1, n = s.length();
        int hash = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            hash = ((hash << 1) & topNum) | (s[i] - '0');

            if (i >= k - 1)
            {
                mp[hash]++;
            }
        }

        return mp.size() == topNum + 1;
    }
};

// Naive approach
class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        if (k > s.length())
            return 0;

        string b(k, '1');
        int n = stoi(b, 0, 2);

        unordered_map<string, int> mp;

        for (int i = 0; i < s.length() + 1 - k; i++)
        {
            string t = s.substr(i, k);
            mp[t]++;
        }

        return mp.size() == n + 1;
    }
};

int main()
{

    return 0;
}