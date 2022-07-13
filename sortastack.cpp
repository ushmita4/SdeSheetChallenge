
void sortedInsert(stack<int> &stack, int current)
{
    if (stack.empty() || current > stack.top())
    {
        stack.push(current);
        return;
    }

    
    int top = stack.top();
    stack.pop();
    
    sortedInsert(stack, current);

    stack.push(top);
}


void sortStack(stack<int> &stack)
{
   
    if (stack.empty())
    {
        return;
    }

   
    int top = stack.top();
    stack.pop();
    
    sortStack(stack);
    sortedInsert(stack, top);
}
