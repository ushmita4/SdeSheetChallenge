
vector<int> getPostOrderTraversal(TreeNode *root)
{

   
    vector<int> answer;

    if (root == NULL)
    {
        return answer;
    }

    TreeNode *current, *predecessor;

  
    current = root;


    while (current != NULL)
    {

        if (current->right == NULL)
        {

            answer.push_back(current->data);


            current = current->left;
        }
        else
        {
           
            predecessor = current->right;
            while (predecessor->left != NULL && predecessor->left != current)
            {
                predecessor = predecessor->left;
            }
           
            if (predecessor->left == current)
            {
                predecessor->left = NULL;
                current = current->left;
            }

            else
            {
                
                answer.push_back(current->data);

               
                predecessor->left = current;

                current = current->right;
            }
        }
    }

    
    reverse(answer.begin(), answer.end());

    return answer;
}
