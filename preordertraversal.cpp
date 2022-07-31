/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/


vector<int> getPreOrderTraversal(TreeNode *root)
{
    
    vector<int> answer;

    if (root == NULL)
    {
        return answer;
    }

    stack<TreeNode *> s;

  
    s.push(root);


    while (s.empty() == false)
    {

        
        TreeNode *node = s.top();

        
        answer.push_back(node->data);

    
        s.pop();

        
        if (node->right)
        {
            s.push(node->right);
        }

       
        if (node->left)
        {
            s.push(node->left);
        }
    }

 
    return answer;
}
