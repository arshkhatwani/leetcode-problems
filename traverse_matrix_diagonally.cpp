#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> &a)
{
    int m = a.size();
    int n = a[m - 1].size();

    int k = 0, j;
    while (k < n)
    {
        j = k;
        for (int i = 0; i < m and j < n; i++)
        {
            cout << a[i][j] << " ";
            j++;
        }
        cout << endl;
        k++;
    }
}

int main()
{
    vector<vector<int>> a = {
        {1, 6, 10, 13, 15},
        {0, 2, 7, 11, 14},
        {0, 0, 3, 8, 12},
        {0, 0, 0, 4, 9},
        {0, 0, 0, 0, 5}};

    print(a);

    return 0;
}