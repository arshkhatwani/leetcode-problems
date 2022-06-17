#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/132-pattern/discuss/94071/Single-pass-C%2B%2B-O(n)-space-and-time-solution-(8-lines)-with-detailed-explanation.

basically humko left wala element minimum se minimum chiye and right wala bich wale se chota but maximum
For this we maintain a monotonic decreasing stack and traverse from back in the array
and we keep a track of the third element in a variable n3=INT_MIN
If we find a[i] < n3 we simply return true
else if a[i] > top of stack we pop all the elements of the stack till its empty or if the top gets >= to the element, while popping we set n3=popped element in every iteration
and we push the element to the stack
*/

class Solution
{
public:
    bool find132pattern(vector<int> &a)
    {
        int n = a.size();
        if (n < 3)
            return false;

        stack<int> s;
        int n3 = INT_MIN;

        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] < n3)
                return true;
            else
                while (!s.empty() and s.top() < a[i])
                {
                    n3 = s.top();
                    s.pop();
                }
            s.push(a[i]);
        }

        return false;
    }
};

int main()
{

    return 0;
}