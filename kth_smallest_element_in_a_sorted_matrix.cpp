#include <bits/stdc++.h>
using namespace std;

/*
Brute force => Priority Queue
push every element in a maxHeap and maintain k elements in in it
TC: O(n2) (nxn matrix)
SC: O(k)

Optimal => Binary Search
Initialise low as smallest element in matrix and high as largest element in matrix
Then while(low < high) calulate mid and then count all the elements in the matrix which are less than mid, for this we will use upper_bound and we will call it in every row of the matrix as every row is sorted
Now if count < k then make low = mid + 1, else high = mid

After the end of while loop, the low will be our answer
TC: O(n^2logn)
SC: O(1)

Video: https://youtu.be/w36ekZYq-Ms

Here "while(low <= high)" can also be used instead of "while(low < high)" and then "high = mid" would be replaced by "high = mid - 1"
*/

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &a, int k)
    {
        int n = a.size();
        int low = a[0][0], high = a[n - 1][n - 1];

        while (low < high)
        // while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int count = 0;

            for (int i = 0; i < n; i++)
            {
                count += upper_bound(a[i].begin(), a[i].end(), mid) - a[i].begin();
            }

            if (count < k)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
                // high = mid - 1; // (for -> while(low <= high))
            }
        }

        return low;
    }
};

int main()
{

    return 0;
}