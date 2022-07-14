

#include <algorithm>
#include <set>


bool compare(vector<int> &job1, vector<int> &job2)
{
    return job1[1] > job2[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{

    sort(jobs.begin(), jobs.end(), compare);

    int maxProfit = 0;
    int maxDeadline = 0;

    
    for (int i = 0; i < jobs.size(); i++)
    {
        maxDeadline = max(maxDeadline, jobs[i][0]);
    }

    
    set<int, greater<int>> slots;

    
    for (int i = maxDeadline; i > 0; i--)
    {
        slots.insert(i);
    }

    for (int i = 0; i < jobs.size(); i++)
    {

    
        if (slots.size() == 0 || jobs[i][0] < *slots.rbegin())
        {
            continue;
        }

        int availableSlot = *slots.lower_bound(jobs[i][0]);
        maxProfit = maxProfit + jobs[i][1];
        slots.erase(availableSlot);
    }

    return maxProfit;
}
