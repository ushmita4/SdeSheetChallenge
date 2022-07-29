#include <queue>

void getBreadth(TreeNode<int> *root, int hrDistance, int &minLeft, int &maxRight)
{
    if (root == NULL)
    {
        return;
    }

  
    getBreadth(root->left, hrDistance - 1, minLeft, maxRight);

    
    getBreadth(root->right, hrDistance + 1, minLeft, maxRight);

    
    minLeft = min(minLeft, hrDistance);
    maxRight = max(maxRight, hrDistance);
}

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    
    vector<int> result;

    
    if (root == NULL)
    {
        return result;
    }

   
    int minLeft = 0, maxRight = 0;

   
    getBreadth(root, 0, minLeft, maxRight);

  
    vector<vector<int>> store(maxRight - minLeft + 1, vector<int>());

  
    int hd = 0;
    int offset = abs(minLeft);

    
    queue<pair<TreeNode<int> *, int>> level;

    level.push(make_pair(root, hd));

    while (level.empty() == false)
    {
        
        pair<TreeNode<int> *, int> temp = level.front();
        level.pop();

        hd = temp.second;

        TreeNode<int> *node = temp.first;

        
        store[hd + offset].push_back(node->data);

        
        if (node->left != NULL)
        {
            level.push(make_pair(node->left, hd - 1));
        }

       
        if (node->right != NULL)
        {
            level.push(make_pair(node->right, hd + 1));
        }
    }

    for (int i = 0; i < store.size(); i++)
    {
        for (int j = 0; j < store[i].size(); ++j)
        {
            result.push_back(store[i][j]);
        }
    }

    
    return result;
}
