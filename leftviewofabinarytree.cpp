

vector<int> getLeftView(TreeNode<int> *root)
{
    
    
    vector<int> leftView;

    if (root == NULL)
    {
        return leftView;
    }

   
    queue<TreeNode<int> *> level;

 
    level.push(root);
    int leftMostNode;

    while (level.empty() == false)
    {
        
      
        int queueSize = level.size();

       
        for (int i = 0; i < queueSize; i++)
        {
            
            
            TreeNode<int> *curr = level.front();
            level.pop();

           
            if (i == 0)
            {
                leftMostNode = curr->data;
            }

            
            if (curr->left != NULL)
            {
                level.push(curr->left);
            }

         
            if (curr->right != NULL)
            {
                level.push(curr->right);
            }
        }

        
        leftView.push_back(leftMostNode);
    }

    
    return leftView;
}
