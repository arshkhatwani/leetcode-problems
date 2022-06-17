#include <bits/stdc++.h>
using namespace std;

/*
We know that there can be multiple numbers formed from a string at a time
like say s = "12345"
here, numbers formed can be: 1,12,123,1234,12345

now lets say if we pick up 1, then we are left with s = "2345"
here, numbers formed can be: 2, 23, 234, 2345

So there can be multiple choices to pick numbers up like instead of 1 we could have picked 12 or maybe 13 or any number from the formed numbers and we need to explore all these combinations till we get a fibonacci sequence.

By the idea of exploring all these combinations we realise its a RECURSION/BACKTRACKING problem

Note that we can get multiple fibonacci sequences if we explore everything but we have to return only one, so the whenever we get a fibonacci sequence we stop right there

Yes while forming numbers we need to keep a check of leading zeros like "01" and we also need to check that any number is not greater than INT_MAX (condition given in problem statement) to avoid integer overflow

So we can keep a track of series array where we store the numbers formed till a particular time and we also keep a track of start index - the index from where we can start forming numbers at a particular time (initially 0)

And while forming numbers
    if the length of the series array is less than 2 we can simply push the formed number at index 'i' to it and make the recursive call where we send the series array and i+1 in place of the start index

    else incase the length is >= 2 we check that if the sum of last 2 elements of the series array is equal to number formed or not. If its equal we push the number into series and make the recursive call, Else we do nothing

    Now in the above 2 conditions we are pushing numbers in series array after the call we dont need the number in the series array as we need the array for the next iteration so we pop the last element pushed (backtrack)

*/

class Solution
{
    vector<int> ans;

    bool checkOverflow(string &s)
    {
        string maxNum = to_string(INT_MAX);

        if (maxNum.length() < s.length())
            return true;

        if (maxNum.length() == s.length() and stoll(s) > stoll(maxNum))
            return true;

        return false;
    }

    void f(string &num, int startIdx, vector<int> series)
    {
        if (startIdx == num.length())
        {
            if (series.size() > 2)
                ans = series;
            return;
        }
        if (ans.size())
            return; // condition to stop all the calls if we found a sequence

        int n = num.length(), len = series.size();
        string numFormed = "";

        // below is the condition to deal with overflow
        if (len >= 2)
        {
            long long sum = (long long)series[len - 1] + (long long)series[len - 2];
            if (sum >= INT_MAX)
                return;
        }

        for (int i = startIdx; i < n; i++)
        {
            numFormed += num[i];

            if (checkOverflow(numFormed))
                break; // again condition to deal with overflow

            int x = stoi(numFormed);
            if (to_string(x) != numFormed)
                break; // condition to deal with leading zeroes

            if (len < 2 or x == series[len - 1] + series[len - 2])
            {
                series.push_back(x);
                f(num, i + 1, series);
                series.pop_back(); // backtracking because we had pushed the number and we need the orignal series array for next iteration
            }

            if (len >= 2 and x > series[len - 1] + series[len - 2])
                break; // to save time
        }
    }

public:
    vector<int> splitIntoFibonacci(string num)
    {
        ans = {};
        vector<int> series;

        f(num, 0, series);

        return ans;
    }
};

int main()
{

    return 0;
}