#include <bits/stdc++.h>
using namespace std;

/*
Brute
The approach is taking every bar and finding maximum width possible using that bar
So we will find the left smaller element to the bar and right smaller element to the bar and calculate the area for the bar. We would do this for every bar and keep track of the maximum

Optimised 1
Since we need to find left and right smaller elements we can find them in an optimised way using the concept of next smaller element(which can be understood by concept of next greater element)
We can use an increasing monotonic stack and store the next smaller element from left and next smaller element from right in separate arrays
Then we can iterate the given array and for every element we can calculate the width using the values of left smaller elements and right smaller elements and get the area for every element and we can keep track of the maximum and return it as answer

Optimised 2
We can further optimise the above approach by doing just a single pass, we found that some elements were inserted into the stack which signifies that after them the smallest element is themselves
So we can find the area of the rectangle by using arr[i] * (right smaller – left smaller -1 )
And keep track of the maximum area

See the video to understand in detail: https://youtu.be/X0X6G-eWgQ8 https://youtu.be/jC_cWLy7jSI
*/

class Solution
{
public:
    int largestRectangleArea(vector<int> &a)
    {
        stack<int> st;
        int n = a.size(), maxArea = 0;

        for (int i = 0; i <= n; i++)
        {
            while (!st.empty() and (i == n or a[st.top()] >= a[i]))
            {
                int height = a[st.top()];
                st.pop();

                int rs = i, ls = !st.empty() ? st.top() : -1;
                int width = rs - ls - 1;

                maxArea = max(maxArea, height * width);
            }

            st.push(i);
        }

        return maxArea;
    }
};

int main()
{

    return 0;
}