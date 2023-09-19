#include <bits/stdc++.h>
using namespace std;

/*
Optimal Solution
TC: O(nlogn) + O(n2)
SC: O(1) (Space taken by 'ans' array is not included)
*/

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &a)
    {
        sort(a.begin(), a.end());
        int n = a.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++)
        {
            if (i > 0 and a[i - 1] == a[i])
                continue;
            int j = i + 1, k = n - 1;

            while (j < k)
            {
                int sum = a[i] + a[j] + a[k];
                if (sum == 0)
                {
                    ans.push_back({a[i], a[j], a[k]});
                    j++, k--;
                    while (j < k and a[j] == a[j - 1])
                        j++;
                    while (j < k and a[k] == a[k + 1])
                        k--;
                }
                else if (sum > 0)
                {
                    k--;
                }
                else
                {
                    j++;
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