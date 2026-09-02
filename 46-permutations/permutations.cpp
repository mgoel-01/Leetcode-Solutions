class Solution {
public:
    void per(vector<int>& nums,vector<int>arr,vector<bool>vis,vector<vector<int>>& ans,int& n){
        if(arr.size()==n){
            ans.push_back(arr);
            return;
        }
        for(int i=0;i<n;i++){
            if(vis[i])continue;
            arr.push_back(nums[i]);
            vis[i]=1;
            per(nums,arr,vis,ans,n);
            arr.pop_back();
            vis[i]=0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> arr;
        vector<bool> vis(n,0);
        per(nums,arr,vis,ans,n);
        return ans;
    }
};