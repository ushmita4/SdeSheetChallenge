/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/


void pathInTree(TreeNode<int>* root, int x, bool& found,vector<int>& result){
    if(!root) return;
    if(root -> data == x){
        found = true;
        result.push_back(root -> data);
        return;
    }
    pathInTree(root -> right, x, found,result);
    if(!found) pathInTree(root -> left, x, found, result);
    if(found) result.push_back(root -> data);        
}

vector<int> pathInATree(TreeNode<int> *root, int x){
    vector<int> result;
    bool found = false;
    pathInTree(root,x,found,result);
    reverse(result.begin(),result.end());
    return result;
}
