#include <bits/stdc++.h>
using namespace std;

/*
Intuitively every senator should ban the right of the upcoming senator. This can be observed using various testcases

A queue can be used to pop the senator and check if its already been eliminated/banned or not.
If the senator is not eliminated then we increment the eliminations of the other party and push the senator back to the queue
If the current senator is eliminated then we just pop the senator and decrement the eliminations of the current senator's party

Once total number of senators of one party gets to 0 we break the iteration and return the answer

See the LeetCode Editorial and code to understand more
*/

class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int n = senate.size(), countD = 0, countR = 0; // total senators of every party
        int rmD = 0, rmR = 0;                          // senators that need to removed / banned
        queue<char> q;

        for (auto i : senate)
        {
            q.push(i);
            countD += (i == 'D');
            countR += (i == 'R');
        }

        while (countD and countR)
        {
            char cur = q.front();
            q.pop();

            if (cur == 'D')
            {
                if (rmD)
                {
                    countD--;
                    rmD--;
                }
                else
                {
                    rmR++;
                    q.push('D');
                }
            }
            else
            {
                if (rmR)
                {
                    countR--;
                    rmR--;
                }
                else
                {
                    rmD++;
                    q.push('R');
                }
            }
        }

        return countD ? "Dire" : "Radiant";
    }
};

int main()
{

    return 0;
}