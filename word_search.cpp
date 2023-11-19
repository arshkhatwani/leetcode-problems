#include <bits/stdc++.h>
using namespace std;

// Solved using backtracking

class Solution
{
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    unordered_map<char, int> mp;

    void count(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char ch = board[i][j];
                mp[ch]++;
            }
        }
    }

    bool check(string &word)
    {
        for (auto ch : word)
        {
            if (mp[ch] == 0)
                return false;
            mp[ch]--;
        }
        return true;
    }

    bool solve(int i, int j, int curLength, vector<vector<char>> &board, string &word)
    {
        int m = board.size(), n = board[0].size();

        if (i < 0 or j < 0 or i == m or j == n)
            return false;
        if (board[i][j] != word[curLength - 1])
            return false;
        if (curLength == word.length())
            return true;

        char ch = board[i][j];
        board[i][j] = '#';

        for (auto d : dir)
        {
            bool ans = solve(i + d[0], j + d[1], curLength + 1, board, word);
            if (ans)
                return true;
        }
        board[i][j] = ch;

        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size(), n = board[0].size();

        count(board);
        if (!check(word))
            return false;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool ans = solve(i, j, 1, board, word);
                if (ans)
                    return true;
            }
        }
        return false;
    }
};

int main()
{

    return 0;
}