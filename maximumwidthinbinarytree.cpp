#include<bits/stdc++.h>
#define ll long long

int getMaxWidth(TreeNode<int> *root)
{
    if(root==nullptr)
        return 0;
    ll ans = 0;
    queue<TreeNode<int>*> q;
    q.push(root);
    while(q.size())
    {
        ll sz = q.size();
        ans = max(ans,sz);
        for(ll i=0;i<sz;i++)
        {
            TreeNode<int>* cur = q.front();
            q.pop();
            if(cur->left)
                q.push(cur->left);
            if(cur->right)
                q.push(cur->right);
        }
    }
    return ans;
}
