#include <bits/stdc++.h>
using namespace std;

/*
We are storing keys and values in a hashmap as (keys, values) for O(1) retrieval when ecryption
Now we are encrypting each and every string in dictionary and we are storing them in a hashmap as (key = encrypted_string, value = frequency)

So for every encrypt command we are simply replacing the value of the chars in string with the values in first hashmap and if any char is not in the hashmap then we are simply returning as empty string as response

And for every decrypt command we are just returning the count of the string from the second hashmap
*/

class Encrypter
{
private:
    unordered_map<char, string> enc;
    unordered_map<string, int> dec;

public:
    Encrypter(vector<char> &keys, vector<string> &values, vector<string> &dictionary)
    {
        enc.clear();
        dec.clear();

        for (int i = 0; i < keys.size(); i++)
        {
            enc[keys[i]] = values[i];
        }

        for (auto i : dictionary)
        {
            string s = encrypt(i);
            if (s.length())
                dec[s]++;
        }
    }

    string encrypt(string word1)
    {
        string ans = "";
        for (auto i : word1)
        {
            if (enc.find(i) != enc.end())
                ans += enc[i];
            else
                return "";
        }
        return ans;
    }

    int decrypt(string word2)
    {
        return dec[word2];
    }
};

int main()
{

    return 0;
}