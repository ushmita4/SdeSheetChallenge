

#include <stack>

vector<int> zigZagTraversal(BinaryTreeNode<int> *root) {


    vector<int> answer;


    if (root == NULL) {
        return answer;
    }
    
    stack<BinaryTreeNode<int>*> oddLevel, evenLevel;

    oddLevel.push(root);

    
    while (evenLevel.empty() == false or oddLevel.empty() == false) {

      
        while (oddLevel.empty() == false) {

           
            BinaryTreeNode<int>* topNode = oddLevel.top();
            oddLevel.pop();

         
            answer.push_back(topNode->data);

           
            if (topNode->left) {
                evenLevel.push(topNode->left);
            }
            if (topNode->right) {

                evenLevel.push(topNode->right);
            }
        }

        
        while (evenLevel.empty() == false) {

            
            BinaryTreeNode<int>* topNode = evenLevel.top();
            evenLevel.pop();

         
            answer.push_back(topNode->data);

            
            if (topNode->right) {
                oddLevel.push(topNode->right);
            }
            if (topNode->left) {
                oddLevel.push(topNode->left);
            }
        }
    }


    return answer;
}
