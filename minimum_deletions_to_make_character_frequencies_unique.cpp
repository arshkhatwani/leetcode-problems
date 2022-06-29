#include <bits/stdc++.h>
using namespace std;

/*
My Logic:
What we could do is we could make an array of count of each element and then sort it in descending order and iterate from start.

Now, while iterating:
if(i > 0 and a[i] >= a[i-1]) we would make a[i] = max(0, a[i - 1] - 1)

We are doing this because if a[i] == a[i-1] it would mean that some 2 characters have same count so in this case we need to delete a character form either a[i] or a[i-1], we are deleting from a[i].

Now if a[i] > a[i-1] we know that this should'nt be possible in a decreasing sorted array. So this tells us there must have been some element in array which is == a[i], because that's why we may have decremented a[i-1] in earlier iterations. So here since we know that there exists an element which we may have encountered before which == a[i]. We can either decrease that element or a[i] so we again make a[i] = max(a[i-1] - 1, 0)

To understand the above case better, consider the following example 3,3,3
here when i = 1, we see a[1] == a[0] => so we make a[1] = a[0] - 1 = 2
now when i = 2, we see a[2] > a[1] and we can also see by eyes that a[0] has same value as a[2] and we dont want same values(character frequencies). So we make a[2] = a[1] - 1.
(Here we are making a[2] = a[1] - 1 and not a[2] = a[0] - 1, because doing a[2] = a[0] - 1 would again result in a[2] == a[1] so we are directly doing a[2] = a[1] - 1.)

TC: O(n) + O(klogk)
SC: O(k)
where n = length of string, k = maximum possible number of distinct characters in string
*/

class Solution
{
public:
    int minDeletions(string s)
    {
        int total = s.length(), sum = 0;
        vector<int> a(26, 0);

        for (auto i : s)
            a[i - 'a']++;

        sort(a.begin(), a.end(), greater<int>());

        for (int i = 0; i < a.size(); i++)
        {
            if (i > 0 and a[i] >= a[i - 1])
                a[i] = max(0, a[i - 1] - 1);

            sum += a[i];
        }

        return total - sum;
    }
};

int main()
{

    return 0;
}