class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        int delrow[]={-1,0,1,0};
        int delcol[]={0,-1,0,1};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int ans=0;
        while(!pq.empty()){
            int eff=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==m-1)return eff;
            if(eff>dist[i][j])continue;
            for(int k=0;k<4;k++){
                int nrow=i+delrow[k];
                int ncol=j+delcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m){
                    int edgeWt=abs(heights[i][j]-heights[nrow][ncol]);
                    int nEff=max(edgeWt,eff);
                    if(nEff<dist[nrow][ncol]){
                        dist[nrow][ncol]=nEff;
                        pq.push({nEff,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;
    }
};