

long long int findMaxSumPathHelper(TreeNode<int> *root, long long int &maxPathSum)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return root->val;
    }

    
    long long int maxSumLeftPath = findMaxSumPathHelper(root->left, maxPathSum);
    
    long long int maxSumRightPath = findMaxSumPathHelper(root->right, maxPathSum);

    
    if (root->left != NULL && root->right != NULL)
    {
        maxPathSum = max(maxPathSum, maxSumLeftPath + maxSumRightPath + root->val);
        return max(maxSumLeftPath, maxSumRightPath) + root->val;
    }
    else if (root->left == NULL)
    {
        return maxSumRightPath + root->val;
    }
    else
    {
        return maxSumLeftPath + root->val;
    }
}

long long int findMaxSumPath(TreeNode<int> *root)
{
    
    long long int maxPathSum = -1;
    findMaxSumPathHelper(root, maxPathSum);
    return maxPathSum;
}
