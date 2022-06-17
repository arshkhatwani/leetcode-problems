#include <bits/stdc++.h>
using namespace std;

/*

Observation,
for ex, k = 5

elements on adding can be divisible by 5 are : (2,3), (23,22), (54,31)
we observe that two numbers on adding are divisible by 5 only and only if their remainders on dividing by 5 can sum up and give 5
Feel free to check the above observation in any example

So now logic is we keep a map to count the remainders of the elements of the array and incase any element is < 0 than we dont store (a[i] % k) instead we store ((a[i] % k) + k) % k in the map actually we store this ((a[i] % k) + k) % k expression for each a[i] in the map as this element doesnt affect any positive element and it takes care of negative elements

Now we iterate the map and we look for two conditions
if key is zero (i.e the remainder stored is 0), then we check that its frequency is even or not if it is not then we return false as it is impossible to divide them into pairs

else if key is not zero, then for key 'x' we check that k - x is present in the map or not
if k-x is not present then we return false
if k-x is present and its frequency(val) is not equal to x then we also return false

On complete iteration it is ensured that the array can be divided into pairs divisible by k so we return true
*/

bool canArrange(vector<int> &a, int k)
{
    int n = a.size();
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
    {
        int x = ((a[i] % k) + k) % k;
        map[x]++;
    }

    int key, val, count0 = 0;
    for (auto i : map)
    {
        key = i.first, val = i.second;

        if (key == 0)
        {
            if (val % 2 == 1)
                return false;
        }
        else
        {
            if (map.find(k - key) != map.end())
            {
                if (map[k - key] != map[key])
                    return false;
            }
            else
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{

    return 0;
}