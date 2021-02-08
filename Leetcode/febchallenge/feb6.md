```
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        vector<int> res;
        //int prev=0;
        int hd=0;
        res.push_back(root->val);
        while(!q.empty())
        {
           
            TreeNode* node=q.front().first;
           // cout<<q.front().first->val<<q.front().second<<endl;
            if(q.front().second!=hd)
                res.push_back(node->val);
          //  cout<<res[res.size()-1]<<endl;
            //q.pop();
            hd=q.front().second;
            q.pop();
            if(node->right)
                q.push({node->right,hd+1});
            if(node->left)
                q.push({node->left,hd+1});
        }
        return res;
    }
};