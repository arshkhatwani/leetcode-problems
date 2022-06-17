#include <bits/stdc++.h>
using namespace std;

// Approach https://youtu.be/8RErc0VXAo8

void reverse(vector<int> &a, int i, int j)
{
    while (i < j)
    {
        swap(a[i], a[j]);
        i++;
        j--;
    }
}

void rotate(vector<int> &a, int k)
{
    int n = a.size();
    k = k % n;
    int diff = n - k;
    reverse(a, 0, diff - 1);
    reverse(a, diff, n - 1);
    reverse(a, 0, n - 1);
}

int main()
{

    return 0;
}