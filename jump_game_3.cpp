#include <bits/stdc++.h>
using namespace std;

/*
Upon trying to traverse the test case with 'false' answer via dry run method it is observed that there will be a cycle in while going from one array element to other

This means if we do a DFS/BFS and we come to a visited node/array element then we know that its not possible to reach the index with 0 value

So we can do a DFS/BFS from 'start' index and we return true only if we reach an element with value 0
If we reach an index which is out of bounds or an index which is already visited then we return false

Space Optimisation:
Instead of keeping a separated visited array we can just modify the given array and set the values at visited indices to -1

Time Complexity: O(n), Since every array element will be visited at most once
Space Complexity: O(1)
*/

class Solution
{
public:
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();

        if (start >= n or start < 0)
            return false;
        if (arr[start] == -1)
            return false;
        if (arr[start] == 0)
            return true;

        int newStart1 = start + arr[start], newStart2 = start - arr[start];
        arr[start] = -1;

        return canReach(arr, newStart1) or canReach(arr, newStart2);
    }
};

// Non space optimised
class Solution
{
    bool solve(int i, vector<int> &a, vector<int> &vis)
    {
        int n = a.size();
        if (i >= n or i < 0)
            return false;
        if (vis[i])
            return false;
        if (a[i] == 0)
            return true;

        vis[i] = 1;
        int ans = solve(i + a[i], a, vis) or solve(i - a[i], a, vis);

        return ans;
    }

public:
    bool canReach(vector<int> &arr, int start)
    {
        int n = arr.size();
        vector<int> vis(n, 0);

        return solve(start, arr, vis);
    }
};

int main()
{

    return 0;
}