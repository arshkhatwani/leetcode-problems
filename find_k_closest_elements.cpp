#include <bits/stdc++.h>
using namespace std;

/*
Logic: https://youtu.be/o-YDQzHoaKM
*/

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        int n = arr.size();
        int low = 0, high = n - k;

        while (low < high)
        {
            int mid = low + (high - low) / 2;

            if (x - arr[mid] > arr[mid + k] - x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid;
            }
        }

        return vector<int>(arr.begin() + low, arr.begin() + low + k);
    }
};

int main()
{

    return 0;
}