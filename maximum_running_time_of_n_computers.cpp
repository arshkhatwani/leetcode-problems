#include <bits/stdc++.h>
using namespace std;

// Go through LC Editorial to understand solutions

// Sorting + Prefix Sum
class Solution
{
public:
    long long maxRunTime(int n, vector<int> &batteries)
    {
        int m = batteries.size();
        long long extra = 0;
        vector<int> a;

        sort(batteries.begin(), batteries.end());
        a.insert(a.begin(), batteries.begin() + m - n, batteries.end());

        for (int i = 0; i < m - n; i++)
        {
            extra += batteries[i];
        }

        int i;
        for (i = 0; i < n - 1; i++)
        {
            long long amount = (long long)(i + 1) * (long long)(a[i + 1] - a[i]);
            if (extra < amount)
            {
                break;
            }

            extra -= amount;
        }
        long long ans = a[i] + extra / (i + 1);

        return ans;
    }
};

// Binary Search
class Solution
{
    bool isPossible(int n, vector<int> &a, long long target)
    {
        int size = a.size();
        long long total = 0;

        for (int i = 0; i < size; i++)
        {
            total += min((long long)a[i], target);
        }

        return total >= n * target;
    }

public:
    long long maxRunTime(int n, vector<int> &a)
    {
        int size = a.size();
        long long sum = 0;

        for (int i = 0; i < size; i++)
        {
            sum += a[i];
        }

        long long low = 0, high = sum, ans = 0;
        while (low <= high)
        {
            long long mid = low + (high - low) / 2;

            if (isPossible(n, a, mid))
            {
                ans = max(ans, mid);
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}