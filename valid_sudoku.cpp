#include <bits/stdc++.h>
using namespace std;

/*
Check all rows any number occuring more than once
Check all cols any number occuring more than once
Check all 3x3 squares any number occuring more than once

if any of above gets false the sudoku is invalid else valid
*/

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<char, int> mp;

        for (int i = 0; i < 9; i++)
        {
            mp.clear();
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                if (mp.find(board[i][j]) != mp.end())
                    return false;
                mp[board[i][j]] = 1;
            }
        }

        for (int i = 0; i < 9; i++)
        {
            mp.clear();
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] == '.')
                    continue;
                if (mp.find(board[j][i]) != mp.end())
                    return false;
                mp[board[j][i]] = 1;
            }
        }

        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                mp.clear();

                for (int row = i; row < i + 3; row++)
                {
                    for (int col = j; col < j + 3; col++)
                    {
                        if (board[row][col] == '.')
                            continue;

                        if (mp.find(board[row][col]) != mp.end())
                            return false;
                        mp[board[row][col]] = 1;
                    }
                }
            }
        }

        return true;
    }
};

int main()
{

    return 0;
}