

void findHead(BinaryTreeNode<int> *root, BinaryTreeNode<int> **head, BinaryTreeNode<int> **prev) {
    
   
    if(root == NULL)
    {
        return ;
    }

    findHead(root->left, head, prev);

    if(*prev == NULL)
    {
        *head = root;
    }
    else
    {
        root->left = *prev;
        (*prev)->right = root;
    }

    *prev = root;

    findHead(root->right, head, prev);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* head = NULL;
    BinaryTreeNode<int>* prev = NULL;
    findHead(root, &head, &prev);

    return head;
}
