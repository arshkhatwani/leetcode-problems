#include <bits/stdc++.h>
using namespace std;

/*
Hint: Consider triplets with elements <= target's elements
*/

class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        int n = triplets.size();
        vector<int> formed = {0, 0, 0};

        for (int i = 0; i < n; i++)
        {
            vector<int> cur = triplets[i];

            if (cur[0] <= target[0] and cur[1] <= target[1] and cur[2] <= target[2])
            {
                formed[0] = max(formed[0], cur[0]);
                formed[1] = max(formed[1], cur[1]);
                formed[2] = max(formed[2], cur[2]);
            }
        }

        if (formed != target)
            return false;
        return true;
    }
};

int main()
{

    return 0;
}