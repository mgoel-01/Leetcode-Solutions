class Solution {
public:
    int maxPro(int ind,int buy,int cap,int n,vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(cap==0)return 0;
        if(ind==n)return 0;
        if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+maxPro(ind+1,0,cap,n,prices,dp),maxPro(ind+1,1,cap,n,prices,dp));
        }
        else{
            profit=max(prices[ind]+maxPro(ind+1,1,cap-1,n,prices,dp),maxPro(ind+1,0,cap,n,prices,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return maxPro(0,1,2,n,prices,dp);
    }
};