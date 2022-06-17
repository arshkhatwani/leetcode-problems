#include <bits/stdc++.h>
using namespace std;

// Read the leetcode hints for logic
// Basically you have to work only using 2 deques

class TextEditor
{
    deque<char> dq1, dq2;

    string leftChars()
    {
        string s = "";
        int total = 10, i = 0;

        for (auto it = dq1.rbegin(); it != dq1.rend() and i < total; it++, i++)
        {
            s += *it;
        }

        reverse(s.begin(), s.end());

        return s;
    }

public:
    TextEditor()
    {
        dq1.clear();
        dq2.clear();
    }

    void addText(string text)
    {
        for (auto i : text)
        {
            dq1.push_back(i);
        }
    }

    int deleteText(int k)
    {
        int total = k;
        while (k-- and !dq1.empty())
        {
            dq1.pop_back();
        }

        return total - k - 1;
    }

    string cursorLeft(int k)
    {
        while (k-- and !dq1.empty())
        {
            dq2.push_front(dq1.back());
            dq1.pop_back();
        }

        return leftChars();
    }

    string cursorRight(int k)
    {
        while (k-- and !dq2.empty())
        {
            dq1.push_back(dq2.front());
            dq2.pop_front();
        }

        return leftChars();
    }
};

int main()
{

    return 0;
}