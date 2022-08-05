#include <bits/stdc++.h>
using namespace std;

/*
BFS Algo can be used to solve this problem
-> Here instead of a visited map/array we first push all the elements in the wordlist to a set from which we would remove the words every time we pop them from queue. This would make the set smaller and smaller which would reduce our time complexity
-> To check if two words satisfy the given condition or not we would change every letter in our popped word one by one and set it to all 26 alphabets one by one and try to find the formed word in the set if the formed word would exist then only we would push it in the queue
-> Every time we would finish a level we would increment our 'ladder' variable (like it does during level order traversal)
-> Whenever the popped word would come equal to endWord we would return ladder as answer
-> If whole BFS is done, it means that we couldn't reach our endWord and we'll return 0 as answer
*/

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end())
            return 0;

        int ladder = 1;
        queue<string> q;
        q.push(beginWord);

        while (!q.empty())
        {
            int n = q.size();

            for (int i = 0; i < n; i++)
            {
                string word = q.front();
                q.pop();

                if (word == endWord)
                    return ladder;

                words.erase(word);

                for (int j = 0; j < word.length(); j++)
                {
                    char defaultChar = word[j];

                    for (char k = 'a'; k <= 'z'; k++)
                    {
                        if (k == defaultChar)
                            continue;

                        word[j] = k;
                        if (words.find(word) != words.end())
                            q.push(word);
                    }

                    word[j] = defaultChar;
                }
            }

            ladder++;
        }

        return 0;
    }
};

int main()
{

    return 0;
}