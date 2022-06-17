#include <bits/stdc++.h>
using namespace std;

// Two pointers approach https://www.geeksforgeeks.org/move-all-zeroes-to-end-of-array-using-two-pointers/

// Two pointers approach
void moveZeroes(vector<int> &a)
{
    int n = a.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0 and a[j] == 0)
            swap(a[i], a[j]);
        if (a[j] != 0)
            j++;
    }
}

// Another approach https://www.geeksforgeeks.org/move-zeroes-end-array/
// void moveZeroes(vector<int> &a)
// {
//     int n = a.size();
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (a[i] != 0)
//         {
//             a[count] = a[i];
//             count++;
//         }
//     }
//     while (count < n)
//     {
//         a[count] = 0;
//         count++;
//     }
// }

int main()
{

    return 0;
}