#include <bits/stdc++.h>
using namespace std;

/*
This question can be solved using BFS
Refer video: https://youtu.be/v1HpZUnQ4Yo
*/

class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        queue<int> q;
        q.push(0);
        int n = s.length(), farthest = 0;

        while (!q.empty())
        {
            int idx = q.front();
            q.pop();
            int start = max(idx + minJump, farthest + 1); // comparing with farthest because if farthest is already covered then we don't have to run the loop again for that

            for (int i = start; i <= min(idx + maxJump, n - 1); i++)
            {
                if (i == n - 1 and s[i] == '0')
                    return true;
                if (s[i] == '0')
                    q.push(i);
            }
            farthest = idx + maxJump;
        }

        return false;
    }
};

int main()
{

    return 0;
}