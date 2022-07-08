class Stack {
    
public:
    
  
    vector<int> myStack;
    
   
    int stackSize;
    
 
    int n;
    
    
    Stack(int n) {
    
        
        this -> myStack.resize(n);
        this -> stackSize = -1;
        this -> n = n;
    }

  
    void push(int num) {
        
       
        if(stackSize != n - 1) {
            
           
            ++stackSize;
            myStack[stackSize] = num;
        }
    }

    
    int pop() {

      
        if(stackSize != -1) {
            
            
            --stackSize;
            return myStack[stackSize + 1];
        }
        else {
            return -1;
        }
    }
    
   
    int top() {
        
        
        if(stackSize != -1) {
            
            
            return myStack[stackSize];
        }
        else {
            return -1;
        }
    }
    
    
    int isEmpty() {
        
        
        if(stackSize != -1) {
            
         
            return 0;
        }
        else {
            return 1;
        }        
    }
    
    
    int isFull() {
        
        
        if(stackSize != n - 1) {
            
           
            return 0;
        }
        else {
            return 1;
        }        
    }
};
