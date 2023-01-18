#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &a, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int n = a.size(), i = 0;
        bool isPushed = false;

        if (n == 0)
            return {newInterval};

        while (i < n)
        {
            if (a[i][0] > newInterval[1])
            {
                ans.push_back(newInterval);
                isPushed = true;
                break;
            }
            else if (a[i][1] >= newInterval[0])
            {
                newInterval[0] = min(newInterval[0], a[i][0]);
                newInterval[1] = max(newInterval[1], a[i][1]);
                i++;
            }
            else
            {
                ans.push_back(a[i]);
                i++;
            }
        }

        if (!isPushed)
            ans.push_back(newInterval);
        while (i < n)
        {
            ans.push_back(a[i]);
            i++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}