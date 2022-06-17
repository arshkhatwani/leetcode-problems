#include <bits/stdc++.h>
using namespace std;

// Logic: https://youtu.be/XlD5VsOZsyA

class StockSpanner
{
private:
    stack<pair<int, int>> s;

public:
    StockSpanner()
    {
        s.empty();
    }

    int next(int price)
    {
        int ans = 1;

        while (!s.empty() and s.top().first <= price)
        {
            ans += s.top().second;
            s.pop();
        }
        s.push({price, ans});

        return ans;
    }
};

int main()
{

    return 0;
}