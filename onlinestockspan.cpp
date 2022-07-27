#include <stack>

vector<int> findSpans(vector<int> &price) {
   
    int n = price.size();

    vector<int> result(n);
    stack<int> stk;

    for(int i = 0; i < n; i++) {
        
        while(stk.empty() == false && price[stk.top()] <= price[i]) {
            stk.pop();
        }

       
        if(stk.empty() == true) {
            result[i] = i + 1;
        } else {
            result[i] = i - stk.top();
        }

        stk.push(i);
    }

    return result;
}
