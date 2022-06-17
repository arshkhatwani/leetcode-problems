#include <bits/stdc++.h>
using namespace std;

/*
We observe that,
    if,    A ^ B = C
    then,  B ^ C = A
    and,   C ^ A = B

So we are caculating prefix xor(let it be xorsum) in each iteration and we also caculate x where x = xorsum ^ b(given in problem) and if x is present in map, we add the frequency of x in our answer

(the above approach will cover edge case like when a[i] = b, it will count it we need not to add an if statement for it)
(if we store map[0] = 1 by default, we need not to write if conditon for edge case when xorsum = b)

Basically the intuition is that if there was x (which is equal to xorsum ^ b) then there must be a subarray of xor=b that exists with which the subarray with xor=x was xor(ed) that it gave xorsum as result on which we are standing right now, so we count the frequency of that x because jitne x honge utni subarrays present hongi na, so wo subarrays count hojayengi humare ans mai

And during the end of the iteration we are incrementing the frequency of xorsum in the map

can read striver's article or watch video for more understanding of the question
*/

int solve(vector<int> &a, int b)
{
    int n = a.size(), xorSum = 0, count = 0;
    unordered_map<int, int> map;
    map[0] = 1; // by adding this line, we are free from adding an if statement for (xorSum == b) in the for loop

    for (int i = 0; i < n; i++)
    {
        xorSum ^= a[i];

        int x = xorSum ^ b;
        if (map.find(x) != map.end())
        {
            count += map[x];
        }

        map[xorSum]++;
    }

    return count;
}

int solve2(vector<int> &a, int b)
{
    int n = a.size(), xorSum = 0, count = 0;
    unordered_map<int, int> map;
    // map[0] = 1;

    for (int i = 0; i < n; i++)
    {
        xorSum ^= a[i];

        if (xorSum == b)
            count++; // by commenting that line above we need to add the if statement here

        int x = xorSum ^ b;
        if (map.find(x) != map.end())
        {
            count += map[x];
        }

        map[xorSum]++;
    }

    return count;
}

int main()
{

    return 0;
}