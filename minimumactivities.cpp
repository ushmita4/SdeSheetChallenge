

#include <algorithm>

int maximumActivities(vector<int> &start, vector<int> &finish) {
    int n = start.size();
    vector<pair<int, int>> activity(n);

    for (int i = 0; i < n; i++) {
        activity[i].first = finish[i];
        activity[i].second = start[i];
    }

   
    sort(activity.begin(), activity.end());

    int maxActivity = 1;
    int currentTime = activity[0].first;

    for (int i = 1; i < n; i++) {

    
        if (activity[i].second >= currentTime) {
            maxActivity++;
            currentTime = activity[i].first;
        }
    }
    return maxActivity;
}
