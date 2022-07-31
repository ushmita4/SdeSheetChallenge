

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *ptr = root;
    
    while(ptr != NULL) {
        if(ptr->data == x) {
            return true;
        } else if(ptr->data > x) {
            // Move 'ptr' to left child. 
            ptr = ptr->left;
        } else {
            // Move 'ptr' to left child. 
            ptr = ptr->right;   
        }
    }

    return false;
}
