

#include<climits>

TreeNode<int>* util(vector<int> &preOrder, int &preIndex, int startRange, int endRange){

    
    if (preIndex >= preOrder.size()){
        return NULL;
    }

    int currNode = preOrder[preIndex];

    
    if (currNode > startRange && currNode < endRange){
        TreeNode<int>* root = new TreeNode<int>(currNode);

       
        preIndex += 1;

        
        if (preIndex < preOrder.size()){
            root -> left = util(preOrder, preIndex, startRange, currNode);
        }
       
        if (preIndex < preOrder.size()){
            root -> right = util(preOrder, preIndex, currNode , endRange);
        }

 
        return root;
    }

    
    return NULL;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    
    int preIndex = 0;

    
    return util(preOrder, preIndex, INT_MIN, INT_MAX);
}
