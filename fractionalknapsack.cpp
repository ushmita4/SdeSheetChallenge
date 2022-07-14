#include <algorithm>
bool compare(pair<int, int>& a, pair<int, int>& b)
{
    double r1 = (double) a.second / a.first;
    double r2 = (double) b.second / b.first;

    return r1 > r2;
}


double maximumValue(vector<pair<int,int>>& items, int n, int w)
{
   
    sort(items.begin(), items.end(), compare);

    double maxValue = 0;
    int currWeight = 0;

    for (int i = 0; i < n; i++)
    {
        if (currWeight + items[i].first <= w)
        {
            currWeight += items[i].first;
            maxValue += items[i].second;
        }
        else
        {
            int remainingWeight = w - currWeight;

           
            maxValue += items[i].second * ((double)remainingWeight / items[i].first);
            break;
        }
    }

    return maxValue;
}
