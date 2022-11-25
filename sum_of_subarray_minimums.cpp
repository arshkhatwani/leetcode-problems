#include <bits/stdc++.h>
using namespace std;

/*
This is similar to largest rectangle in histogram problem

For every element a[i] (index = i) in array
We find next smaller element to the left(nsel) and next smaller element to right(nser) for a[i]

We calculate the number of left direction subarrays formed by a[i] where a[i] will be minimum = i - (nsel[i] + 1)

We calculate the number of right direction subarrays formed by a[i] where a[i] will be minimum = nser[i] - 1 - i

Then we calculate the subarrays in both directions this we would get my multiplying the count of left and right subarrays

Then one more subarray would be formed of length 1 i.e the element a[i] itself

Then we would add up all these subarray counts and multiply the total by a[i] and add it to our answer


Here to handle duplicate elements set strict less than and strict less than equal to when finding nsel and nser
either we can keep 'strict less than' in nsel and 'strict less than equal to' in nser
or we can keep 'strict less than' in nser and 'strict less than equal to' in nsel

TC: O(n)
SC: O(n)
*/

// Single pass solution
class Solution
{
public:
    int sumSubarrayMins(vector<int> &a)
    {
        int n = a.size();
        stack<int> st;
        long long left, right, count, ans = 0, MOD = 1e9 + 7;

        for (int i = 0; i <= n; i++)
        {
            while (i == n or (!st.empty() and a[st.top()] >= a[i]))
            {
                int popped = st.top();
                st.pop();

                left = !st.empty() ? popped - st.top() - 1 : popped;
                right = i - popped - 1;
                count = left + right + left * right + 1; // 1 => self subarray

                ans += (count * a[popped]) % MOD;
                ans %= MOD;

                if (st.empty())
                    break;
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

public:
    int sumSubarrayMins(vector<int> &a)
    {
        vector<int> nsel = nseFromLeft(a);
        vector<int> nser = nseFromRight(a);

        int n = a.size();
        long long ans = 0;
        long long MOD = 1e9 + 7;

        for (int i = 0; i < n; i++)
        {
            int leftSubs = i - (nsel[i] + 1);
            int rightSubs = nser[i] - 1 - i;
            int leftAndRight = leftSubs * rightSubs;
            int solo = 1;

            long long total = leftSubs + rightSubs + leftAndRight + solo;
            total = total % MOD;
            ans += (a[i] % MOD) * total;
            ans = ans % MOD;
        }

        return ans;
    }
};

int main()
{

    return 0;
}