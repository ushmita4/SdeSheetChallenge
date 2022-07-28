#include <queue>

vector<int> findMedian(vector<int> &arr, int n){
    
   
    vector<int> medians;
    
   
    priority_queue<int> lo;  
    
                              
    priority_queue<int, vector<int>, greater<int>> hi;   
    
    for(int i = 0; i < n; i++){
        
        int num = arr[i];
        
     
        lo.push(num);                                
        
        
        hi.push(lo.top());                        
        lo.pop();

       
        if (lo.size() < hi.size()) {                    
            lo.push(hi.top());
            hi.pop();
        }
        
        int median;
        
       
        if(lo.size() > hi.size()){
            
            median = lo.top();
            
        }
        
        else{
            
            median = (lo.top() + hi.top())/2;  
            
        }
        
        medians.push_back(median);
    }
    
    return medians;

    
}

