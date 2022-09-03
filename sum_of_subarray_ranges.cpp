#include <bits/stdc++.h>
using namespace std;

/*
Since subarray range = abs(maximum element - minimum element),
Therefore sum of subarray ranges = abs(sum of all maximum elements - sum of all minimum elements)

So just like we solved Sum of Subarray Minimums problem we can also find sum of subarray maximums and take out their difference and return it as answer
*/

// Better optimised solution
class Solution
{
public:
    long long subArrayRanges(vector<int> &a)
    {
        int n = a.size();
        stack<int> st;
        long long ans = 0;

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && a[st.top()] > (i == n ? -2e9 : a[i]))
            {
                int j = st.top();
                st.pop();

                int k = st.empty() ? -1 : st.top();
                ans -= (long)a[j] * (i - j) * (j - k);
            }
            st.push(i);
        }

        st = stack<int>();
        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() && a[st.top()] < (i == n ? 2e9 : a[i]))
            {
                int j = st.top();
                st.pop();

                int k = st.empty() ? -1 : st.top();
                ans += (long)a[j] * (i - j) * (j - k);
            }
            st.push(i);
        }

        return ans;
    }
};

class Solution
{
    vector<int> nseFromLeft(vector<int> &a)
    {
        int n = a.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and a[st.top()] > a[i])
            {
                st.pop();
            }

            if (st.empty())
                nse[i] = -1;
            else
                nse[i] = st.top();

            st.push(i);
        }

        return nse;
    }
    vector<int> nseFromRight(vector<int> &a)
    {
        int n = a.size();
        vector<int> nse(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and a[st.top()] >= a[i])
            {
                st.pop();
            }

            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }

        return nse;
    }
    vector<int> ngeFromLeft(vector<int> &a)
    {
        int n = a.size();
        vector<int> nge(n);
        stack<int> st;

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() and a[st.top()] < a[i])
            {
                st.pop();
            }

            if (st.empty())
                nge[i] = -1;
            else
                nge[i] = st.top();

            st.push(i);
        }

        return nge;
    }
    vector<int> ngeFromRight(vector<int> &a)
    {
        int n = a.size();
        vector<int> nge(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() and a[st.top()] <= a[i])
            {
                st.pop();
            }

            if (st.empty())
                nge[i] = n;
            else
                nge[i] = st.top();

            st.push(i);
        }

        return nge;
    }

public:
    long long subArrayRanges(vector<int> &a)
    {
        vector<int> nsel = nseFromLeft(a);
        vector<int> nser = nseFromRight(a);
        vector<int> ngel = ngeFromLeft(a);
        vector<int> nger = ngeFromRight(a);

        int n = a.size();
        long long ans = 0, sumMin = 0, sumMax = 0;

        for (int i = 0; i < n; i++)
        {
            int leftSubs = i - (nsel[i] + 1);
            int rightSubs = nser[i] - 1 - i;
            int leftAndRight = leftSubs * rightSubs;

            int leftSubsMax = i - (ngel[i] + 1);
            int rightSubsMax = nger[i] - 1 - i;
            int leftAndRightMax = leftSubsMax * rightSubsMax;

            long long totalMin = leftSubs + rightSubs + leftAndRight;
            long long totalMax = leftSubsMax + rightSubsMax + leftAndRightMax;

            sumMin += totalMin * a[i];
            sumMax += totalMax * a[i];
        }

        ans = abs(sumMax - sumMin);

        return ans;
    }
};

int main()
{

    return 0;
}