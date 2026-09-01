class Solution {
public:
    int maxiCoins(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            int coins=nums[i-1]*nums[k]*nums[j+1]+maxiCoins(i,k-1,nums,dp)+maxiCoins(k+1,j,nums,dp);
            maxi=max(coins,maxi);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return maxiCoins(1,n-2,nums,dp);
    }
};