class Solution {
public:
    int countWays(int i,int n,string s,vector<int>&dp){
        if(i>=n){
            return 1;
        }
        if(dp[i]!=-1)return dp[i];
        int pick1=0;
        if(s[i]-'0'!=0)pick1=countWays(i+1,n,s,dp);
        int pick2=0;
        int num=0;
        if(i<n-1) num=((s[i]-'0')*10)+(s[i+1]-'0');
        if(i<n-1 && num>9 && num<=26)pick2=countWays(i+2,n,s,dp);
        return dp[i]= pick1+pick2;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        return countWays(0,n,s,dp);
    }
};