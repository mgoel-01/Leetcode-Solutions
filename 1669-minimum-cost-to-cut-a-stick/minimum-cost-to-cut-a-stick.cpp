class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        int l=cuts.size();
        vector<vector<int>> dp(l,vector<int>(l,0));
        sort(cuts.begin(),cuts.end());
        for(int i=l-2;i>=1;i--){
            for(int j=i;j<=l-2;j++){
                int mini=INT_MAX;
                for(int ind=i;ind<=j;ind++){
                    int cost=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][l-2];
    }
};