class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)return -1;
        int delrow[]={0,1,0,-1,-1,1,-1,1};
        int delcol[]={1,0,-1,0,1,-1,-1,1};
        queue<pair<pair<int,int>,int>> q;
        vector<int> dist((n*n),1e9);
        dist[0]=1;
        q.push({{0,0},1});
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dis=q.front().second;
            q.pop();
            for(int x=0;x<8;x++){
                int nrow=i+delrow[x];
                int ncol=j+delcol[x];
                if(nrow<0 || ncol<0 ||nrow>=n || ncol>=n)continue;
                int node=n*nrow+ncol;
                if(grid[nrow][ncol]==0 && (dis+1<dist[node])){    
                    dist[node]=dis+1;
                    q.push({{nrow,ncol},dis+1});
                }
            }
        }
        if(dist[(n*n)-1]==1e9)return -1;
        return dist[(n*n)-1];
    }
};