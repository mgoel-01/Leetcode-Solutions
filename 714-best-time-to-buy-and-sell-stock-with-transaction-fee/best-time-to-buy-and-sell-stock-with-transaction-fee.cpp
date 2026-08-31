class Solution {
public:
    int maxPro(int ind,int buy,int n,int fee,vector<int>& prices,vector<vector<int>>& dp){
        if(ind>=n)return 0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        int profit=0;
        if(buy){
            profit=max(-prices[ind]-fee+maxPro(ind+1,0,n,fee,prices,dp),maxPro(ind+1,1,n,fee,prices,dp));
        }
        else{
            profit=max(prices[ind]+maxPro(ind+1,1,n,fee,prices,dp),maxPro(ind+1,0,n,fee,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return maxPro(0,1,n,fee,prices,dp);
    }
};