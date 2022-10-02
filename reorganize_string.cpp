#include <bits/stdc++.h>
using namespace std;

/*
HINT: Alternate placing the most common letters.

First we take count of all letters then store them in a maxHeap with characters sorted by their count
Then we keep popping characters from priority queue and add them once then reduce their freq then push them back again in prioriy queue if their freq is still > 0
If the top of pq is same as the last char of the result string then we pop it and then add the next top and then push the next top back if its freq > 0 and also we push the top which we popped earlier

If the top of pq is same as the last char of the result string then we pop it and if pq gets empty after popping that means no other character is left which means the answer is not possible so we return ""

TC: O(n) (for iterating the string) + O(26log(26)) => O(n)
SC: O(26)(hashmap) + O(26)(max heap) => O(1)

Another approach: https://leetcode.com/problems/reorganize-string/discuss/232469/Java-No-Sort-O(N)-0ms-beat-100
*/

class Solution
{
public:
    string reorganizeString(string s)
    {
        unordered_map<char, int> count;
        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            count[s[i]]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto i : count)
        {
            pq.push({i.second, i.first});
        }

        string ans = "";
        while (!pq.empty())
        {
            char lastChar = ans.length() ? ans[ans.length() - 1] : ' ';
            pair<int, char> top = pq.top();

            if (top.second == lastChar)
            {
                pq.pop();

                if (pq.empty())
                    return "";

                else
                {
                    pair<int, char> nextTop = pq.top();
                    pq.pop();

                    nextTop.first -= 1;
                    ans += nextTop.second;

                    if (nextTop.first != 0)
                        pq.push(nextTop);
                    pq.push(top);
                }
            }
            else
            {
                pq.pop();
                top.first -= 1;
                ans += top.second;

                if (top.first != 0)
                    pq.push(top);
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}