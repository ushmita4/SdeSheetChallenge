

#include <stack>

int kthSmallest(TreeNode<int> *root, int k)
{
    
    stack<TreeNode<int> *> st;

    while (1)
    {
        while (root != NULL)
        {
            
            st.push(root);

            root = root->left;
        }

        root = st.top();
        st.pop();

        if (k == 1)
        {
            return root->data;
        }

       
        k = k - 1;

        root = root->right;
    }
}
