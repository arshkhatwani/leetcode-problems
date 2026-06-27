"""
This problem is a bit tricky.

First we count the number of seats in the corridor. If the number of seats is 0 or odd, we return 0.

Then we iterate through the corridor and count the number of seats in each section.

Here the intuition is that we can partition the corridor after every even-numbered seat (2nd, 4th, ...) and before every odd-numbered seat starting from the 3rd (3rd, 5th, ...).
The number of ways here would be the difference between the current index (on the 3rd / 5th / ... seat) and the index of the second seat of the previous pair.

Suppose the corridor is "SSPPSS"
Here we can partition the corridor after the 2nd seat(idx = 1) and before the 3rd seat(idx = 4).

So the number of ways here would be (4 - 1) = 3
SS|PPSS, SSP|PSS, SSPP|SS

And we multiply this number of ways calculated with the answer variable.
The reason we multiply is that the divider choices between each pair of adjacent pairs are independent, so the total number of ways is the product of the individual gaps.

Note: we only have to start this process after the first pair of seats is formed.
"""

class Solution:
    def numberOfWays(self, corridor: str) -> int:
        MOD = 10**9 + 7
        cnt = 0

        for s in corridor:
            if s == "S":
                cnt += 1
        if cnt == 0 or cnt % 2:
            return 0

        ans = 1
        last_s_idx = -1
        cnt = 0
        for i in range(len(corridor)):
            if corridor[i] == "S":
                cnt += 1
            if cnt > 2 and cnt % 2 and corridor[i] == "S":
                ans = (ans * (i - last_s_idx)) % MOD

            if corridor[i] == "S":
                last_s_idx = i

        return ans
