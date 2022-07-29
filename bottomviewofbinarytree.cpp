

vector<int> bottomView(BinaryTreeNode<int> *root) {
   
    int horizontalDistance = 0;

  
    map<int, BinaryTreeNode<int> *> mp;
    queue<pair<BinaryTreeNode<int> *, int>> q;
   
    q.push({root, 0});
    while (!q.empty()) {
        pair<BinaryTreeNode<int> *, int> p = q.front();
        q.pop();

       
        mp[p.second] = p.first;

        
        if (p.first->left != NULL) {
            q.push({p.first->left, p.second - 1});
        }
   
        if (p.first->right != NULL) {
            q.push({p.first->right, p.second + 1});
        }
    }
    vector<int> answer;

   
    for (auto i = mp.begin(); i != mp.end(); i++) {
        answer.push_back(i->second->data);
    }
    return answer;
}
