

#include <algorithm>


vector<int> getInOrderTraversal(BinaryTreeNode<int> *root) {

   
    vector<int> answer;

  
    if (root == NULL) {
        return answer;
    }

    
    BinaryTreeNode<int> *current, *predecessor;


    current = root;

   
    while (current != NULL) {
        if (current->left == NULL) {
            answer.push_back(current->data);
            current = current->right;
        }
        else {

            
            predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }

            if (predecessor->right == NULL) {
               
                predecessor->right = current;
                current = current->left;
            }
            else {
              
                predecessor->right = NULL;
                answer.push_back(current->data);
                current = current->right;
            }
        }
    }

    return answer;
}


vector<int> getPreOrderTraversal(BinaryTreeNode<int> *root) {

    
    vector<int> answer;

  
    if (root == NULL) {
        return answer;
    }

    
    BinaryTreeNode<int> *current, *predecessor;

  
    current = root;

   
    while (current != NULL)
    {
        if (current->left == NULL)
        {
           
            answer.push_back(current->data);

            
            current = current->right;
        }
        else
        {
            
            predecessor = current->left;
            while (predecessor->right && predecessor->right != current) {
                predecessor = predecessor->right;
            }
            
            
            if (predecessor->right == current) {
                predecessor->right = NULL;
                current = current->right;
            }

            else {
               
                answer.push_back(current->data);

               
                predecessor->right = current;

               
                current = current->left;
            }
        }
    }

    return answer;
}


vector<int> getPostOrderTraversal(BinaryTreeNode<int> *root) {

    
    vector<int> answer;

 
    if (root == NULL) {
        return answer;
    }

    
    BinaryTreeNode<int> *current, *predecessor;

 
    current = root;

   
    while (current != NULL)
    {
        
        if (current->right == NULL)
        {
           
            answer.push_back(current->data);

            // Move to left child of current.
            current = current->left;
        }
        else
        {
          
            predecessor = current->right;
            while (predecessor->left != NULL && predecessor->left != current) {
                predecessor = predecessor->left;
            }
           
            if (predecessor->left == current) {
                predecessor->left = NULL;
                current = current->left;
            }

            else {
               
                answer.push_back(current->data);

               
                predecessor->left = current;

              
                current = current->right;
            }
        }
    }

    
    reverse(answer.begin(), answer.end());

    
    return answer;
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    vector<vector<int>> result(3);

    
    result[0] = getInOrderTraversal(root);

    
    result[1] = getPreOrderTraversal(root);

    
    result[2] = getPostOrderTraversal(root);

    
    return result;
}
