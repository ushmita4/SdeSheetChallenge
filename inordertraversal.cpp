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
vector<int> getInOrderTraversal(TreeNode *root)
{
    
    vector<int> answer;

 
    if (root == NULL)
    {
        return answer;
    }

    
    stack<TreeNode *> s;

    TreeNode *current = root;

    
    while (current != NULL || s.empty() == false)
    {
        while (current != NULL)
        {
           
            s.push(current);

            
            current = current->left;
        }

        
        current = s.top();

       
        s.pop();

       
        answer.push_back(current->data);

       
        current = current->right;
    }

 
    return answer;
}
