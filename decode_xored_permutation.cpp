#include <bits/stdc++.h>
using namespace std;

/*
For example, original list is[a1, a2, a3, a4, a5], which means encoded list is [a1^a2, a2^a3, a3^a4, a4^a5].

We can get a1^a2, a1^a3, a1^a4, a1^a5 after iterating encoded list.

And we can compute a1^a2^a3^a4^a5 beforehand.

Then by xor all of them we can get the first element a1:
(a1^a2) ^ (a1^a3) ^ (a1^a4) ^ (a1^a5) ^ (a1^a2^a3^a4^a5) = a1
*/

class Solution
{
    int getXorOfN(int n)
    {
        int total = 0;
        for (int i = 1; i <= n; i++)
            total ^= i;
        return total;
    }

public:
    vector<int> decode(vector<int> &encoded)
    {
        int n = encoded.size() + 1;
        int xorN = getXorOfN(n), xorWithFirstEl = 0, totalXor = 0;
        ;

        for (int i = 0; i < n - 1; i++)
        {
            xorWithFirstEl ^= encoded[i];
            totalXor ^= xorWithFirstEl;
        }

        int firstEl = xorN ^ totalXor;

        vector<int> ans;
        ans.push_back(firstEl);
        for (int i = 0; i < n - 1; i++)
        {
            int el = ans[ans.size() - 1] ^ encoded[i];
            ans.push_back(el);
        }

        return ans;
    }
};

int main()
{

    return 0;
}