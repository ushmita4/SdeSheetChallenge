

#include <unordered_map>


TreeNode<int> *constructTree(int inStart, int inEnd, int &pIndex, unordered_map<int, int> &inorderIndex, vector<int> &preorder)
{
    if (inStart > inEnd)
    {
        // Subtree is empty.
        return NULL;
    }

    // Get root node value from preorder sequence.
    int rootNode = preorder[pIndex];

    // Increment the index denoting the first element of preorder traversal.
    pIndex = pIndex + 1;

    // Create the root node with "rootNode" value.
    TreeNode<int> *root = new TreeNode<int>(rootNode);

    if (inStart == inEnd)
    {
        // There is a single node in the given subtree.
        return root;
    }
    else
    {
        // Get the index of root node value using the HashMap.
        int inIndex = inorderIndex[root->data];

        // Recur for the left subtree.
        TreeNode<int> *leftChild = constructTree(inStart, inIndex - 1, pIndex, inorderIndex, preorder);

        // Recur for the right subtree.
        TreeNode<int> *rightChild = constructTree(inIndex + 1, inEnd, pIndex, inorderIndex, preorder);

        // Link the left and right child to the root node.
        root->left = leftChild;
        root->right = rightChild;

        return root;
    }
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    // A HashMap to store the <nodeValue, index> pair of inorder sequence.
    unordered_map<int, int> inorderIndex;

    for (int i = 0; i < inorder.size(); i++)
    {
        // Storing key, value pair
        inorderIndex[inorder[i]] = i;
    }

    // Index of the first element of the preorder sequence
    int pIndex = 0;

    return constructTree(0, inorder.size() - 1, pIndex, inorderIndex, preorder);
}
