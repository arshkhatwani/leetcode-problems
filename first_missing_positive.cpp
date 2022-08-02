#include <bits/stdc++.h>
using namespace std;

/*
We know that ans would be in range (1, n+1) because the array has 'n' elements and we are finding the smallest positive number here

We can sort the array and do binary search for every number in range (1, n+1) that would work in O(nlogn) time

We can also keep a hashmap(or count array) store every element and find it later that would work in O(n) time and O(n) space

We can optimise space here by making our input array as hashmap:
to do this we can iterate our array and
-> for every a[i] if  1 <= a[i] <= n we can add it to index = a[i] - 1,
-> to avoid the loss of element present at index a[i] - 1 we swap(a[i], a[a[i] - 1])
-> doing this operation can result in shifting some upcoming element to our current index which might not be processed in upcoming iteration and can result in wrong ans

To understand the above point, consider the following testcase, a = [3,4,-1,1]
if we iterate this array at index 0 after swapping our array would look like [-1,4,3,1] as element 3 would be swapped with -1

Now in 2nd iteration, array would look like [-1,1,3,4] after swapping 4 with 1. Here what happened is 1 got shifted to current index and 4 got shifted to upcoming index this would result in unability to process element 1 as 1 was upcoming and now at its place(index) already processed element is present.

So to solve this issue we use a while loop and we keep on swapping and sending elements to their desired postion until we get an element i.e not in range[1,n+1] or if the element at that index is already the desired element (i.e for ex a[2] = 3) we do this desired element check to avoid infinite loop
so our loop would look like => while (a[i] <= n and a[i] >= 1 and a[i] != i + 1 and a[a[i] - 1] != a[i])

Now after processing the whole array, we take variable ans = 1 and we keep trying to find ans in the array if ans is found we increment it if it isnt found we break the loop and return it we run the loop till ans <= n
*/

class Solution
{
public:
    int firstMissingPositive(vector<int> &a)
    {
        int n = a.size();

        for (int i = 0; i < n; i++)
        {
            while (a[i] <= n and a[i] >= 1 and a[i] != i + 1 and a[a[i] - 1] != a[i])
            {
                swap(a[i], a[a[i] - 1]);
            }
        }

        int ans = 1;
        while (ans <= n)
        {
            if (a[ans - 1] == ans)
                ans++;
            else
                break;
        }

        return ans;
    }
};

int main()
{

    return 0;
}