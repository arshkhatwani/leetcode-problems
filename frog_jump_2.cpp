#include <bits/stdc++.h>
using namespace std;

/*
To check if a distance is valid:
We need to first take the largest jump we can such that it fits the distance (i.e less than or equal to given distance)
If we cannot take any jumps further then the distance is not possible

After reaching the end we need to do the same but this time we need to take largest jumps for the stones which are unvisited

To find the minimum possible distance:
we can binary search the distance, our initial low will be 1 and initial high wil be (last element - first element)

Pseudo code for checking if a distance is valid:
ind = 0
while(ind < n):
    find the largest index 'j' where a[j] - a[ind] <= dist
    if(ind == j) return false
    ind = j
    vis[ind] = true

while(ind != 0):
    find the smallest index 'j' where a[ind] - a[j] <= dist and vis[j] == false
    if(ind == j) return false
    ind = j

return true

Video to understand more: https://youtu.be/jKs7fVc0R2c
*/

class Solution
{
    int isPossible(int dist, vector<int> &a)
    {
        int n = a.size(), idx = 0, newIdx = 0, j = 0;
        vector<int> vis(n, 0);

        while (idx != n - 1)
        {
            while (j < n and a[j] - a[idx] <= dist)
                newIdx = j, j++;
            if (newIdx == idx)
                return 0;
            idx = newIdx;
            vis[idx] = 1;
        }
        j = n - 1;
        while (idx != 0)
        {
            while (j >= 0 and a[idx] - a[j] <= dist)
            {
                if (vis[j] == 0)
                    newIdx = j;
                j--;
            }
            if (newIdx == idx)
                return 0;
            idx = newIdx;
            vis[idx] = 1;
        }
        return 1;
    }

public:
    int maxJump(vector<int> &a)
    {
        int n = a.size();
        int low = 1, high = a[n - 1] - a[0], ans = high;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (isPossible(mid, a))
            {
                ans = min(mid, ans);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}