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
    int cnt=0;
    void sumTree(TreeNode* root,int& sum,int& n){
        if(!root)return;
        sumTree(root->left,sum,n);
        sumTree(root->right,sum,n);
        sum+=root->val;
        n++;
    }
    void traverse(TreeNode* root,int& sum,int& n){
        if(!root)return;
        traverse(root->left,sum,n);
        traverse(root->right,sum,n);
        sum=0;
        n=0;
        sumTree(root,sum,n);
        if(root->val==(sum/n))cnt++;
    }
    int averageOfSubtree(TreeNode* root) {
        int sum=0;
        int n=0;
        traverse(root,sum,n);
        return cnt;
    }
};