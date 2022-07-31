

#include <string>

string serializeTree(TreeNode<int> *root)
{
    
    
    string serialized = "";

    
    queue<TreeNode<int> *> level;
    level.push(root);

    while (level.empty() == false)
    {
        
        
        TreeNode<int> *curr = level.front();
        level.pop();

       
        if (curr != NULL)
        {
            
          
            serialized.append(to_string(curr->data));
            serialized.push_back(',');

            
            level.push(curr->left);
            level.push(curr->right);
        }

       
        else
        {
            
           
            serialized.append("-1,");
        }
    }

   
    return serialized;
}

TreeNode<int> *deserializeTree(string &serialized)
{

    //    Pointer for reading elements from the serialized binary tree.
    int ptr = 0;
    string firstVal = "";

    //    Read the first value from the string.
    while (ptr < serialized.length() && serialized[ptr] != ',')
    {
        firstVal.push_back(serialized[ptr]);
        ptr++;
    }
    ptr++;
    int val = stoi(firstVal);

    //    If the first value if -1 then return null.
    if (val == -1)
    {
        return NULL;
    }

    //    Create a new root node.
    TreeNode<int> *root = new TreeNode<int>(val);

    //    Queue for level order traversal.
    queue<TreeNode<int> *> level;

    //    Push the root node into the queue.
    level.push(root);

    while (level.empty() == false)
    {
        
        //    Pop the front node from the queue.
        TreeNode<int> *curr = level.front();
        level.pop();

        string leftChild = "";

        //    Read the value of the left child.
        while (ptr < serialized.length() && serialized[ptr] != ',')
        {
            leftChild.push_back(serialized[ptr]);
            ptr++;
        }
        ptr++;
        string rightChild = "";

        //    Read the value of the right child.
        while (ptr < serialized.length() && serialized[ptr] != ',')
        {
            rightChild.push_back(serialized[ptr]);
            ptr++;
        }
        ptr++;

        int leftChildValue = stoi(leftChild);
        int rightChildValue = stoi(rightChild);

        //    If the left child node is not null
        if (leftChildValue != -1)
        {
            
            //    Create new left child node.
            TreeNode<int> *leftNode = new TreeNode<int>(leftChildValue);
            curr->left = leftNode;

          
            level.push(curr->left);
        }

      
        if (rightChildValue != -1)
        {
            
            
            TreeNode<int> *rightNode = new TreeNode<int>(rightChildValue);
            curr->right = rightNode;

         
            level.push(curr->right);
        }
    }

  
    return root;
}
