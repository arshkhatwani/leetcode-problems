#include <bits/stdc++.h>
using namespace std;

/*
billion             9 (%3 == 0) (ones)
hundred million     8 (%3 == 2) (hundreds)
ten million         7 (%3 == 1) (tens)
million             6 (%3 == 0) (ones)
hundred thousand    5 (%3 == 2) (hundreds)
ten thousand        4 (%3 == 1) (tens)
thousand            3 (%3 == 0) (ones)
hundred             2 (%3 == 2) (hundreds)
tens                1 (%3 == 1) (tens)
ones                0 (%3 == 0) (ones)

We would traverse the given number from right to left i.e from one's place to end place and we'll keep a track of index (initialised to 0)

We would have to deal differently with 10s place i.e when (index % 3 == 1) because it has cases like (10, 20, 11, 13, 17, 30, 50 90 etc.) which have different spellings her we also have to use the element at ones place to find the spelling (for example 14 -> Fourteen)

If we are at ones or hundreds place (irrespective of thousand, million or billion) we just need to pick a single number and then we have to use 'hundred' (if at hundred place) and family name
(for example 1000 -> one thousand 100000 -> one hundred thousand)

Since we are traveersing from right to left we are pushing everything into stack and at the end we pop everything out and add it into ans string

Every time idx % 3 == 0 we enter a new family (example: thousand to million)

See the code to understand
*/

class Solution
{
    vector<string> family = {"", "Thousand", "Million", "Billion"};
    unordered_map<int, string> words;

    void makeMap()
    {
        words[1] = "One";
        words[2] = "Two";
        words[3] = "Three";
        words[4] = "Four";
        words[5] = "Five";
        words[6] = "Six";
        words[7] = "Seven";
        words[8] = "Eight";
        words[9] = "Nine";
        words[10] = "Ten";
        words[11] = "Eleven";
        words[12] = "Twelve";
        words[13] = "Thirteen";
        words[14] = "Fourteen";
        words[15] = "Fifteen";
        words[16] = "Sixteen";
        words[17] = "Seventeen";
        words[18] = "Eighteen";
        words[19] = "Nineteen";
        words[20] = "Twenty";
        words[30] = "Thirty";
        words[40] = "Forty";
        words[50] = "Fifty";
        words[60] = "Sixty";
        words[70] = "Seventy";
        words[80] = "Eighty";
        words[90] = "Ninety";
    }

public:
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";

        makeMap();
        stack<string> st;

        int familyIdx = 0, recentNumsEl = 0;

        for (int idx = 0; num > 0; num /= 10, idx++)
        {
            int curNum = num % 10;

            if (idx % 3 == 0)
            {
                /*
                We are adding the while loop to check for families which had only 0 in all 3 places (ones, tens, hundreds)
                To understand this, take case like: 1000000
                Without this while loop ans would be: "One Million Thousand"
                Correct ans is: "One Million"
                */
                while (!st.empty() and find(family.begin(), family.end(), st.top()) != family.end())
                    st.pop();

                st.push(family[familyIdx]);
                familyIdx++;
            }

            if (curNum and idx % 3 == 1)
            {
                int tensNum = curNum * 10 + recentNumsEl;

                if (tensNum > 10 and tensNum < 20) // for example if number is 14 then it would be fourteen and four will already be present in stack so we need to pop out four first
                {
                    st.pop();
                    st.push(words[tensNum]);
                }
                else // for example if number is 99 then it would be ninety nine and nine will already be present in stack so we just need only add the number at tens place
                {
                    tensNum -= recentNumsEl;
                    st.push(words[tensNum]);
                }
            }
            else if (curNum)
            {
                if (idx % 3 == 2)
                    st.push("Hundred");

                st.push(words[curNum]);
            }

            if (idx % 3 == 0)
            {
                recentNumsEl = curNum; // storing this recent num because we need its use in tens place
            }
        }

        string ans;

        // here while adding strings from stack we are avoiding to add strings which are ""
        while (!st.empty())
        {
            if (st.top() == "")
            {
                st.pop();
                continue;
            }

            ans += st.top();
            st.pop();
            if (!st.empty() and st.top() != "")
                ans += " ";
        }

        return ans;
    }
};

int main()
{

    return 0;
}