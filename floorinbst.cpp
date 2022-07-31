
int floorInBST(TreeNode<int> * root, int X)
{
   
    if(root == NULL)
    {
        return INT_MAX;
    }
  
 
    if(root -> val == X)
    {
        return root -> val;
    }
  
   
    if(root -> val > X)
    {
        return floorInBST(root -> left, X);
    }
  
   
    int floorValue = floorInBST(root -> right, X);

    return (floorValue <= X) ? floorValue : root -> val;
}
