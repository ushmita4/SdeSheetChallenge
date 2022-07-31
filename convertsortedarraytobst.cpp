
struct nodeData
{
    TreeNode<int> *node;

    
    int low, high;

    nodeData(TreeNode<int>* root, int left, int right)
    {
        node = root;
        low = left ;
        high = right;
    }
};


TreeNode<int>* sortedArrToBST (vector<int> &arr, int n)
{
    
    TreeNode<int>* root = new TreeNode<int> (-1);
    stack<nodeData> st;

    nodeData node = nodeData(root, 0, n - 1);
    st.push(node); 

    while (st.empty() == false)
    {
        nodeData curNode = st.top();
        st.pop();

       
        int mid = curNode.low + (curNode.high - curNode.low) / 2;
        curNode.node -> val = arr[mid];

        
        if (curNode.low < mid)
        {
            curNode.node -> left = new TreeNode<int>(-1);

            node = nodeData(curNode.node -> left, curNode.low, mid - 1);
            st.push(node);
        }

       
        if (curNode.high > mid) 
        {
            curNode.node -> right = new TreeNode<int>(-1);
            
            node = nodeData(curNode.node -> right, mid+1, curNode.high);
            st.push(node);
        }
    }


    return root;
}
