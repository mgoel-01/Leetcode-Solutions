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
    vector<int> largestValues(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            int s=q.size();
            int maxi=INT_MIN;
            while(s--){
                TreeNode* cur=q.front();
                q.pop();
                maxi=max(maxi,cur->val);
                if(cur->left)q.push(cur->left);
                if(cur->right)q.push(cur->right);
            } 
            ans.push_back(maxi);           
        }
        return ans;
    }
};