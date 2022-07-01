#include <unordered_map>

#include <vector>

bool commonIdx(pair < int, int > p1, pair < int, int > p2) {
  return p1.first == p2.first || p1.first == p2.second || p1.second == p2.first || p1.second == p2.second;
}

string fourSum(vector < int > arr, int target, int n) {
  unordered_map < int, pair < int, int >> mp;

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      mp[arr[i] + arr[j]] = {
        i,
        j
      };
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int requiredSum = target - (arr[i] + arr[j]);

      if (mp.find(requiredSum) != mp.end() && !commonIdx(mp[requiredSum], {
          i,
          j
        })) {
        return "Yes";
      }
    }
  }

  return "No";
}
