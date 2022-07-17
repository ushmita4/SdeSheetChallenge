

#include <stack>

int largestRectangle(vector < int > & heights) {

    int n = heights.size();

    
    stack < int > s;

    int maxArea = 0;

    
    int topOfStack;


    int areaWithTop;

    
    int i = 0;
    while (i < n) {
       
        if (s.empty() || heights[s.top()] <= heights[i]) {
            s.push(i++);
        }
       
        else {
            topOfStack = s.top();
            s.pop();

           
            if (s.empty()) {
                areaWithTop = heights[topOfStack] * i;
            } else {
                areaWithTop = heights[topOfStack] * (i - s.top() - 1);
            }

            if (maxArea < areaWithTop) {
                maxArea = areaWithTop;
            }
        }
    }

    
    while (s.empty() == false) {
        topOfStack = s.top();
        s.pop();

        if (s.empty()) {
            areaWithTop = heights[topOfStack] * i;
        } else {
            areaWithTop = heights[topOfStack] * (i - s.top() - 1);
        }

        if (maxArea < areaWithTop) {
            maxArea = areaWithTop;
        }
    }

    return maxArea;
}
