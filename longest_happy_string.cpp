#include <bits/stdc++.h>
using namespace std;

/*
The approach for this problem is same as Reorganize String
*/

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pair<int, char>> pq;
        if (a)
            pq.push({a, 'a'});
        if (b)
            pq.push({b, 'b'});
        if (c)
            pq.push({c, 'c'});

        string ans = "";

        while (!pq.empty())
        {
            char last = ans.length() > 0 ? ans[ans.length() - 1] : ' ';
            char secondLast = ans.length() > 1 ? ans[ans.length() - 2] : ' ';

            pair<int, char> top = pq.top();

            if (last == secondLast and last == top.second)
            {
                pq.pop();
                if (pq.empty())
                    break;

                pair<int, char> secondTop = pq.top();
                pq.pop();
                ans += secondTop.second;

                secondTop.first -= 1;
                if (secondTop.first)
                    pq.push(secondTop);
                pq.push(top);
            }
            else
            {
                pq.pop();
                ans += top.second;

                top.first -= 1;
                if (top.first)
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