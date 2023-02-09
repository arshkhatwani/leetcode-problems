#include <bits/stdc++.h>
using namespace std;

/*
Take two variables (a, b) to store values and two variables (countA, countB) to store counts
Take two pointers(i, j) to iterate the array

First initialise the first element as to 'a'
Then start iterating through the array with the 'j' pointer

If b is uninitialized (i.e no value is given i.e -1) or if arr[j] == b or arr[j] == a, then
    if arr[j] == a, increment countA by 1
    else, increment countB by 1 and make b = arr[j]

else,
We know that we have gotten a third type of fruit so we now need to increment 'i' pointer till any of the countA or countB gets to 0
If both countA and countB have become 0, then we make j = i, reset 'b' (i.e make b = -1) and set a = arr[i]
If countA gets to 0 then we swap(a,b) and swap(countA, countB) and reset 'b' (i.e make b = -1)
If countB gets to 0 then we reset 'b' (i.e make b = -1)

At every point we try to maximise our result by finding the maximum value of 'countA' + 'countB'

See the code to understand more
*/

class Solution
{
public:
    int totalFruit(vector<int> &arr)
    {
        int n = arr.size(), i = 0, j = 0, ans = 0;
        int a = arr[i], b = -1, countA = 0, countB = 0;

        while (j < n)
        {
            if (arr[j] == b or b == -1 or arr[j] == a)
            {
                if (arr[j] == a)
                {
                    countA++;
                }
                else
                {
                    b = arr[j];
                    countB++;
                }
                j++;
            }
            else
            {
                while (countA != 0 and countB != 0)
                {
                    if (arr[i] == a)
                        countA--;
                    if (arr[i] == b)
                        countB--;
                    i++;
                }
                if (countA == 0 and countB == 0)
                {
                    j = i;
                    a = arr[i];
                    b = -1;
                }
                else if (countA == 0)
                {
                    swap(a, b);
                    swap(countA, countB);
                    b = -1;
                }
                else if (countB == 0)
                {
                    b = -1;
                }
            }
            ans = max(ans, countA + countB);
        }

        return ans;
    }
};

int main()
{

    return 0;
}