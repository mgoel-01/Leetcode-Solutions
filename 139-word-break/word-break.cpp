class Solution {
public:
    bool canSegmented(int i,int j,int n,string s,vector<string>& wordDict,vector<vector<int>>& dp){
        if(i==n)return true;
        if(j==n)return false;
        if(dp[i][j]!=-1)return dp[i][j];
        bool isTrue1=false;
        string str=s.substr(i,j-i+1);
        if(find(wordDict.begin(),wordDict.end(),str)!=wordDict.end()){
            isTrue1=canSegmented(j+1,j+1,n,s,wordDict,dp);
        }
        bool isTrue2=canSegmented(i,j+1,n,s,wordDict,dp);
        return dp[i][j]=isTrue1||isTrue2;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));
        for(int j=0;j<=n;j++)dp[n][j]=true;
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=i;j--){
                bool isTrue1=false;
                string str=s.substr(i,j-i+1);
                if(find(wordDict.begin(),wordDict.end(),str)!=wordDict.end()){
                    isTrue1=dp[j+1][j+1];
                }
                bool isTrue2=dp[i][j+1];
                dp[i][j]=isTrue1||isTrue2;
            }
        }
        return dp[0][0];
    }
};