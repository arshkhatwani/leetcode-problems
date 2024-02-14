#include <bits/stdc++.h>
using namespace std;

/*
A stack can be used to solve this problem

1. Take a stack, it will be used to store a sum and a sign
2. When iterating if a digit is encountered, form a number (till the digits are over) and add the number to the sum
3. When '-' is encountered set the sign to -1
4. When '(' is encountered push the current sum and sign as a pair in stack and reset the sum = 0 and sign = 1
5. Start calculating the sum and sign as before
6. When ')' pop the {sum, sign} from stack and set the currentSum = poppedSum + (currentSum * sign)
7. Return the sum after iteration is complete
*/

class Solution
{
public:
    int calculate(string s)
    {
        stack<pair<int, int>> st;
        int sign = 1;
        long long sum = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                long long num = 0;
                while (i < s.size() and isdigit(s[i]))
                {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                sum += num * sign;
                sign = 1;
            }
            else if (s[i] == '(')
            {
                st.push({sum, sign});
                sum = 0;
                sign = 1;
            }
            else if (s[i] == ')')
            {
                int prevSum = st.top().first;
                int signBefore = st.top().second;
                sum = prevSum + (sum * signBefore);
                st.pop();
            }
            else if (s[i] == '-')
            {
                sign = -1;
            }
        }

        return sum;
    }
};

int main()
{

    return 0;
}