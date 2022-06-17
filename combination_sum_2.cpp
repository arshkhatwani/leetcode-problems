#include <bits/stdc++.h>
using namespace std;

/*
This is a variation of Combination Sum 1 problem.
Here we can sort the array and we can iterate into elements one by one and for any recursion call during iteration if prev element is equal to current element then we wont pick up the element again in order to save time and not do unnecessary recursion calls

Watch video to understand more https://youtu.be/G1fRTGRxXU8
*/

class Solution
{
private:
    vector<vector<int>> ans;
    void solve(vector<int> &arr, int idx, int target, vector<int> a)
    {
        if (target == 0)
        {
            ans.push_back(a);
        }

        for (int i = idx; i < arr.size(); i++)
        {
            if (i > idx and arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;

            a.push_back(arr[i]);
            solve(arr, i + 1, target - arr[i], a);
            a.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &arr, int target)
    {
        ans.clear();
        sort(arr.begin(), arr.end());
        vector<int> a;
        solve(arr, 0, target, a);
        return ans;
    }
};

int main()
{

    return 0;
}