#include <bits/stdc++.h>
using namespace std;

/*
- We can use a map which takes O(nlogn) time to find, add, erase keys
- We store very element and its count as key,value pair in the map
- Then we find the least element and keep on incrementing it and try to find it again till the group size is over
- If at any point we could not find the element that means we cannot divide it into groups hence we return false
- We keep continuing this above process till the mp gets empty
- If the whole iteration is completed then we know that we can divide it into groups hence we return true

See the code to understand more
*/

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;

        map<int, int> mp;

        for (auto i : hand)
        {
            mp[i] += 1;
        }

        while (!mp.empty())
        {
            int size = groupSize;
            int least = mp.begin()->first;
            int toFind = least;

            while (size)
            {
                if (mp.find(toFind) == mp.end())
                {
                    return false;
                }
                mp[toFind] -= 1;
                if (mp[toFind] == 0)
                {
                    mp.erase(toFind);
                }

                toFind += 1;
                size--;
            }
        }

        return true;
    }
};

int main()
{

    return 0;
}