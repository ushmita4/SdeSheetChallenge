

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *currentNode = root;

    while (currentNode != NULL)
    {
        if (currentNode->left != NULL)
        {
            
            TreeNode<int> *predecessor = currentNode->left;

            while (predecessor->right != NULL)
            {
                predecessor = predecessor->right;
            }

          
            predecessor->right = currentNode->right;

           
            currentNode->right = currentNode->left;

            currentNode->left = NULL;
        }

       
        currentNode = currentNode->right;
    }

    return root;
}
