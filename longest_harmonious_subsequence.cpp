#include <bits/stdc++.h>
using namespace std;

// Approach 1 sorting
int findLHS(vector<int> &a)
{
    int n = a.size();
    if (n == 1)
        return 0;
    sort(a.begin(), a.end());

    int i = 0, j = 1;
    int ans = 0;
    while (j < n)
    {
        int diff = a[j] - a[i];
        if (diff == 1)
        {
            ans = max(ans, j - i + 1);
            j++;
        }
        else if (diff < 1)
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    return ans;
}

// Approach 2 hashmap
// int findLHS(vector<int> &a)
// {
//     int n = a.size(), ans = 0;
//     unordered_map<int, int> count;
//     for (int i = 0; i < n; i++)
//     {
//         count[a[i]]++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         int less = count[a[i] - 1];
//         int more = count[a[i] + 1];
//         if (less or more)
//             ans = max(ans, count[a[i]] + max(less, more));
//     }
//     return ans;
// }

int main()
{

    return 0;
}