class Solution {
public:
    bool isPallindrome(string& str){
        return equal(str.begin(),str.begin()+str.size()/2,str.rbegin());
    }
    int miniCut(int i,int n,string s,vector<int>& dp){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int mini=INT_MAX;
        string temp="";
        for(int j=i;j<n;j++){
            temp+=s[j];
            int cost=INT_MAX;
            if(isPallindrome(temp))cost=1+miniCut(j+1,n,s,dp);
            mini=min(cost,mini);
        }
        return dp[i]=mini;
    }
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            int mini=INT_MAX;
            string temp="";
            for(int j=i;j<n;j++){
                temp+=s[j];
                int cost=INT_MAX;
                if(isPallindrome(temp))cost=1+dp[j+1];
                mini=min(cost,mini);
            }
            dp[i]=mini;
        }
        return dp[0]-1;
    }
};