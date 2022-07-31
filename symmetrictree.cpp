

bool checkSymmetricity(BinaryTreeNode<int>* firstRoot, BinaryTreeNode<int>* secondRoot)
{
    
    
    if(firstRoot == NULL && secondRoot == NULL)
    {
        return true;
    }

    
    if( (firstRoot == NULL && secondRoot != NULL) || (firstRoot != NULL && secondRoot == NULL) )
    {
        return false;
    }

    
    if(firstRoot->data != secondRoot->data)
    {
        return false;
    }

    
   
    return checkSymmetricity(firstRoot->right, secondRoot->left) && checkSymmetricity(firstRoot->left, secondRoot->right);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    return checkSymmetricity(root, root); 
}
