#include <bits/stdc++.h>
using namespace std;

/*
Here the question has asked the distinct prime factors of product of all elements of the array

Instead of first calculating the product we can calculate the prime factors of each element individually and keep them in a map

Then at the end we return the count of keys in the map (map.size())

Prime Factor calculation logic:
-> While n is divisible by 2, count 2 and divide n by 2.

-> After the above, n must be odd. Now we start a loop from i = 3 to the square root of n. While i divides n, count i, and divide n by i. After i fails to divide n, increment i by 2 and continue.

-> If n is a prime number and is greater than 2, then n will not become 1 by the above two steps. So count n if it is greater than 2.
*/

class Solution
{
    unordered_map<int, int> primes;

    void primeFactors(int n)
    {
        while (n % 2 == 0)
        {
            n /= 2;
            primes[2]++;
        }

        for (int i = 3; i <= sqrt(n); i += 2)
        {
            while (n % i == 0)
            {
                primes[i]++;
                n /= i;
            }
        }

        if (n > 2)
            primes[n]++;
    }

public:
    int distinctPrimeFactors(vector<int> &nums)
    {
        primes.clear();

        for (auto n : nums)
        {
            primeFactors(n);
        }

        return primes.size();
    }
};

int main()
{

    return 0;
}