

#include <algorithm>
#include <vector>


void swap(string &s, int i, int j) {
    char te = s[i];
    s[i] = s[j];
    s[j] = te;
}

void findPermutationsHelper(string &s, int i, int j, vector <string> &ans) {
    if (i >= j) {
      
        string permutation = "";

        for (int k = 0; k < s.length(); k++) {
            permutation += (s[k]);
        }

        ans.push_back(permutation);
        return;
    }

    
    for (int k = i; k <= j; k++) {
        swap(s, i, k);

        findPermutationsHelper(s, i + 1, j, ans);

        swap(s, i, k);
    }

}

vector <string> findPermutations(string &s) {
   
    vector <string> ans;

    
    findPermutationsHelper(s, 0, s.length() - 1, ans);

    return ans;
}
