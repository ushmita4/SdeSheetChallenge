

class minStack
{
    stack<int> Stack, Min;
    
    public:
        
        
        minStack() { }
        
       
        void push(int num)
        {
            Stack.push(num);
            if(Min.empty() || Min.top() >= num){
                Min.push(num);
            }
        }
        
   
        int pop()
        {
            if(!Min.empty() && Min.top() == Stack.top()) {
                Min.pop();
            }

            int ret = -1;

            if(!Stack.empty()) {
                ret = Stack.top();
                Stack.pop();
            }

            return ret;
        }
        
        
        int top()
        {
            int ret = -1;
            if(!Stack.empty()){
                ret = Stack.top();
            }
            return ret;
        }
        
        
        int getMin()
        {
            int ret = -1;
            if(!Min.empty()) {
                ret = Min.top();
            }
            return ret;
        }
};
