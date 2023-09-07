#include <bits/stdc++.h>
using namespace std;

// Go through LC Hints to understand logic

class Solution
{
    long long MOD = 1e9 + 7;
    int primeScore(int n)
    {
        int count = 0;
        bool flag;

        for (int i = 2; i * i <= n; i++)
        {
            flag = false;
            while (n % i == 0)
            {
                n = n / i;
                if (!flag)
                    count++;
                flag = true;
            }
        }
        if (n > 1)
        {
            count++;
        }
        return count;
    }
    long long expo(long long x, long long y)
    {
        long long res = 1;
        while (y)
        {
            if (y % 2)
                res = (res * x) % MOD;
            x = (x * x) % MOD;
            y /= 2;
        }
        return res;
    }

public:
    int maximumScore(vector<int> &a, int k)
    {
        int n = a.size();
        vector<int> idx(n), ps, left(n), right(n);

        for (int i = 0; i < n; i++)
        {
            idx[i] = i;
            ps.push_back(primeScore(a[i]));
        }
        sort(idx.begin(), idx.end(), [&](int i, int j)
             { return a[i] > a[j]; });

        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and ps[st.top()] < ps[i])
            {
                right[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            right[st.top()] = n;
            st.pop();
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and ps[st.top()] <= ps[i])
            {
                left[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty())
        {
            left[st.top()] = -1;
            st.pop();
        }

        long long res = 1;
        for (auto i : idx)
        {
            long long el = a[i];
            long long p = (i - left[i]) * (right[i] - i);
            p = min(p, (long long)k);
            k -= p;
            res = res * expo(el, p);
            res %= MOD;
            if (k == 0)
                break;
        }

        return res;
    }
};

int main()
{

    return 0;
}