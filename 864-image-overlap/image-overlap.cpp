class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int cnt=0;
        int n=img1.size();
        int m=img1[0].size();
        int maxi=0;
        for(int k=-n+1;k<n;k++){
            for(int l=-m+1;l<m;l++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(i+k>n-1 || i+k<0)continue;
                        if(j+l>m-1 || j+l<0)continue;
                        if(img1[i][j]==img2[i+k][j+l] && img1[i][j]==1)cnt++;
                    }
                }
                maxi=max(maxi,cnt);
                cnt=0;
                
            }
        }
        
        return maxi;
    }
};