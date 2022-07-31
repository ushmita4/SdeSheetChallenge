

bool helper(BinaryTreeNode<int>* root, BinaryTreeNode<int>*& prev) {
   
    if (root) {
        if (!helper(root->left, prev)) {  
            return false;
        }

        if (prev != NULL && root->data < prev->data)  
        {
            return false;
        }

        prev = root;

        return helper(root->right, prev);  
    }

    return true;
}

bool validateBST(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* prev = NULL;
    return (helper(root, prev));
}
