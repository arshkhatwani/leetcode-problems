#include <bits/stdc++.h>
using namespace std;

/*
Simple Approach
Take 2 stacks s1, s2
for every iteration in nums1 put all the elements of nums2 in the s1 now start popping adn pushing the popped ones into s2 till the s1.top gets equal to the element of nums1 then start popping elements from s2 until you get s2.top > element then add it to answer

Efficient Approach
We iterate in nums2 from behind and we store the elements in decreasing monotonic stack
For every element we compare the top of the stack if top is greater than the element then we store the answer for that particular element in the hashmap
if the top <= element, then we keep popping until the stack is empty or the top gets greater than element.
Now if the stack is empty, we store the answer = -1 in map else we store the top of the stack in the map as answer and we push the element into the stack

Now we iterate the nums1 and add the answers to our MAIN answer to every elements in nums1
*/

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        stack<int> s;
        unordered_map<int, int> map;

        for (int j = nums2.size() - 1; j >= 0; j--)
        {
            int i = nums2[j];
            if (!s.empty() and s.top() > i)
            {
                map[i] = s.top();
            }
            else
            {
                while (!s.empty() and s.top() <= i)
                {
                    s.pop();
                }
                map[i] = s.empty() ? -1 : s.top();
            }
            s.push(i);
        }

        vector<int> ans;
        for (auto i : nums1)
        {
            ans.push_back(map[i]);
        }

        return ans;
    }
};

int main()
{

    return 0;
}