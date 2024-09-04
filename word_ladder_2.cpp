#include <bits/stdc++.h>
using namespace std;

class Solution
{
    void dfs(string word, vector<string> &seq, unordered_map<string, int> &mp, vector<vector<string>> &ans)
    {
        if (mp.find(word) != mp.end() and mp[word] == 1)
        {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int sz = word.length();
        int steps = mp[word];
        for (int i = 0; i < sz; i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                if (mp.find(word) != mp.end() and mp[word] == steps - 1)
                {
                    seq.push_back(word);
                    dfs(word, seq, mp, ans);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        vector<vector<string>> ans;
        unordered_set<string> st(wordList.begin(), wordList.end());
        unordered_map<string, int> mp;
        queue<string> q;

        int sz = beginWord.length();
        mp[beginWord] = 1;
        q.push(beginWord);
        st.erase(beginWord);

        while (!q.empty())
        {
            string word = q.front();
            int steps = mp[word];
            q.pop();

            if (word == endWord)
                break;

            for (int i = 0; i < sz; i++)
            {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    word[i] = ch;
                    if (st.count(word))
                    {
                        mp[word] = steps + 1;
                        q.push(word);
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        for (auto i : mp)
        {
            cout << i.first << " " << i.second << endl;
        }

        if (mp.find(endWord) != mp.end())
        {
            vector<string> seq = {endWord};
            dfs(endWord, seq, mp, ans);
        }
        return ans;
    }
};

int main()
{

    return 0;
}