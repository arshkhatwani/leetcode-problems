#include <bits/stdc++.h>
using namespace std;

/*
Problem link: https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

Here we have to sort all the jobs in decreasing order of profit

Since we are using greedy approach we will do a job at its last day because if we do it earlier we might miss out on some profits

And if we have already done another job on that last day then we will do the current job at any free slot that comes before last day

To understand more: https://youtu.be/LjPx4wQaRIs
*/

struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

bool comp(Job a, Job b)
{
    return a.profit > b.profit;
}

class Solution
{
public:
    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, comp);
        unordered_map<int, int> mp;
        int totalProfit = 0, maxDeadline = 0;

        for (int i = 0; i < n; i++)
        {
            maxDeadline = max(maxDeadline, arr[i].dead);
        }

        for (int i = 0; i < n; i++)
        {
            int dead = arr[i].dead, profit = arr[i].profit;

            while (mp.find(dead) != mp.end())
            {
                dead--;
            }

            if (mp.find(dead) == mp.end() and dead > 0)
            {
                mp[dead] = arr[i].id;
                totalProfit += profit;
            }

            if (mp.size() == maxDeadline)
                break;
            // when all slots are filled, there is no need to iterate through the remaining jobs so we break the loop and it reduces the time complexity of the code
        }

        int totalJobs = mp.size();
        return {totalJobs, totalProfit};
    }
};

int main()
{

    return 0;
}