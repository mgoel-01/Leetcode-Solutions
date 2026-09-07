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
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return canSegmented(0,0,n,s,wordDict,dp);
    }
};