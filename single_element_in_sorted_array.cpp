#include <bits/stdc++.h>
using namespace std;

// Logic: https://youtu.be/PzszoiY5XMQ

// int singleNonDuplicate(vector<int> &a)
// {
//     int n = a.size(), low = 0, high = n - 1, mid;

//     if (n == 1)
//         return a[0];

//     while (low <= high)
//     {
//         mid = low + (high - low) / 2;
//         if (mid % 2 == 0)
//         {
//             if (a[mid] == a[mid + 1])
//             {
//                 low = mid + 1;
//             }
//             else
//             {
//                 high = mid - 1;
//             }
//         }
//         else
//         {
//             if (a[mid] == a[mid + 1])
//             {
//                 high = mid - 1;
//             }
//             else
//             {
//                 low = mid + 1;
//             }
//         }
//     }

//     return a[low];
// }

// Above solution contains a lot of if-else statements so to simplify it
// Below is the cleaner code
/*
Let a number be 'x'
if x is odd, x^1 will give even number before x
if x is even, x^1, will give odd number after x
*/
int singleNonDuplicate(vector<int> &a)
{
    int n = a.size(), low = 0, high = n - 1, mid;

    if (n == 1)
        return a[0];

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (a[mid] == a[mid ^ 1])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return a[low];
}

int main()
{

    return 0;
}