#include <bits/stdc++.h>
using namespace std;

/*
Calculate every subarray and if it satisfy the conditions then store it in a set and return the size of the set as the answer
*/

class Solution
{
public:
    int countDistinct(vector<int> &a, int k, int p)
    {
        int n = a.size(), count;
        set<vector<int>> mp;

        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            count = 0;

            for (int j = i; j < n; j++)
            {

                if (a[j] % p == 0)
                    count++;

                if (count <= k)
                {
                    temp.push_back(a[j]);
                    mp.insert(temp);
                }
                else
                    break;
            }
        }

        return mp.size();
    }
};

int main()
{

    return 0;
}