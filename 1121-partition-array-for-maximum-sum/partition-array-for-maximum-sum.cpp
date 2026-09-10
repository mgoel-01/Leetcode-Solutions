class Solution {
public:
    int maxSum(int i,int k,int n,vector<int>&arr,vector<int>& dp){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int maxi=INT_MIN;
        int maxS=INT_MIN;
        for(int j=i;j<k+i && j<n;j++){
            maxi=max(maxi,arr[j]);
            int sum=maxi*(j-i+1)+maxSum(j+1,k,n,arr,dp);
            maxS=max(maxS,sum);
        }
        return dp[i]=maxS;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return maxSum(0,k,n,arr,dp);
    }
};