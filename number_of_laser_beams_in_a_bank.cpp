#include <bits/stdc++.h>
using namespace std;

/*
The brute force would be to iterate the matrix and store the count of 1s in every row in an array if and only if count of 1s is != 0

Then iterate the array from 0th to (n-2)th index and in every iteration add (a[i] * a[i+1]) to the answer

TC : O(m x n) + O(m)
SC : O(m)

The optimal solution would be to store the count of 1s in previous filled row and the current row in two variables (say prev and curr initialised to zero and curr initialised everytime when a new row comes) and if the count of 1s in current row is > 0 (i.e curr > 0) then add (prev * curr) into the answer and update prev as curr

TC : O(m x n)
SC : O(1)
*/

// Brute
class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        vector<int> a;
        int m = bank.size(), n = bank[0].size();

        for (int i = 0; i < m; i++)
        {
            int count1 = 0;
            for (int j = 0; j < n; j++)
            {
                if (bank[i][j] == '1')
                    count1++;
            }
            if (count1)
                a.push_back(count1);
        }

        int ans = 0, size = a.size();
        for (int i = 0; i < size - 1; i++)
        {
            ans += a[i] * a[i + 1];
        }

        return ans;
    }
};

// Optimal
class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int m = bank.size(), n = bank[0].size(), prev = 0, curr = 0, ans = 0;

        for (int i = 0; i < m; i++)
        {
            curr = 0;
            for (int j = 0; j < n; j++)
            {
                if (bank[i][j] == '1')
                    curr++;
            }
            if (curr)
            {
                ans += prev * curr;
                prev = curr;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}