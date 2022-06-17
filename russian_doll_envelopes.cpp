#include <bits/stdc++.h>
using namespace std;

/*
[[1,2],[2,3],[3,4],[3,5],[4,5],[5,5],[5,6],[6,7],[7,8]]
*/

/*
The idea is to sort the array with increasing width and decreasing length and take an array and push the first length in it
Then in every iteration we have to binary search(lower bound) the current length in the array:
    if it is found or we got the index returned next to it (feature of lower bound) then we have to just replace the length in the search result with this current length
    else we just push it to the array and increment our answer by 1

Decreasing length isliye rkhi hai taaki same width mai aage koi choti length wala envelop mile toh hum usko apni dp array mai push/replace karlen taaki aage usse bade envelop milne ki chance aaye toh wo hum apne ans mai add kar saken
*/

int maxEnvelopes(vector<vector<int>> &a)
{
    sort(a.begin(), a.end(), [](const vector<int> &a, const vector<int> &b)
         {
                 if(a[0]<b[0])
                     return true;
                 if(a[0]==b[0])
                     return a[1]>b[1];
                 return false; });

    int n = a.size(), ans = 1, prev = 0;
    vector<int> dp;

    dp.push_back(a[0][1]);

    for (int i = 1; i < a.size(); i++)
    {
        auto it = lower_bound(dp.begin(), dp.end(), a[i][1]);

        if (it == dp.end())
        {
            ans++;
            dp.push_back(a[i][1]);
        }
        else
        {
            *it = a[i][1];
        }
    }

    // for(int i = 0; i < dp.size(); i++){
    //     cout << dp[i] << " ";
    // } // just for checking out dp

    return ans;
}

int main()
{

    return 0;
}