

TreeNode<int>* buildTreeHelper(vector<int>& postOrder, int postStart, int postEnd, vector<int>& inOrder, int inStart, int inEnd) 
{
    if (postStart > postEnd || inStart > inEnd) 
    {
        return NULL;
    }

   
    int rootVal = postOrder[postEnd];
    
    TreeNode<int>* root = new TreeNode<int>(rootVal);

   
    int k = 0;
    
    
    for (int i = inStart; i <= inEnd; i++) 
    {
        if (rootVal == inOrder[i]) 
        {
            k = i;
            break;
        }
    }

   
    root -> left = buildTreeHelper(postOrder, postStart, postStart + k - inStart - 1, inOrder, inStart, k - 1);
    root -> right = buildTreeHelper(postOrder, postStart + k - inStart, postEnd - 1, inOrder, k + 1, inEnd);

    return root;
}

TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
    int n = postOrder.size();

    int postStart = 0;
    int postEnd = n - 1;
    int inStart = 0;
    int inEnd = n - 1;

    return buildTreeHelper(postOrder, postStart, postEnd, inOrder, inStart, inEnd);
}

