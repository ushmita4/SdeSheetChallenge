

void changeTree(BinaryTreeNode<int> *root) {

    
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        return;
    }

    
    int difference = root->data - ((root->left ? root->left->data : 0) + (root->right ? root->right->data : 0));

   
    if (difference > 0) {
        if (root->left) {
            root->left->data += difference;
        }
        else {
            root->right->data += difference;
        }
    }

    
    changeTree(root->left);
    changeTree(root->right);

  
    root->data =  ((root->left ? root->left->data : 0) + (root->right ? root->right->data : 0));
}
