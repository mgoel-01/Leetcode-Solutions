class Solution {
public:
    vector<int> delrow={-1,0,1,0};
    vector<int> delcol={0,1,0,-1};
    bool isExist(int i,int j,int k,int m,int n,int len,vector<vector<char>>& board,string word,vector<int>& vis){
        if(board[i][j]!=word[k])return false;
        if(k==len-1)return true;
        bool isTrue=false;
        for(int x=0;x<4;x++){
            int nrow=i+delrow[x];
            int ncol=j+delcol[x];
            int node=nrow*n+ncol;
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && vis[node]==0){
                vis[node]=1;
                isTrue=isTrue|isExist(nrow,ncol,k+1,m,n,len,board,word,vis);
                vis[node]=0;
            }
        }
        return isTrue;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        int len=word.size();
        bool isTrue=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vector<int> vis(n*m,0);
                vis[i*n+j]=1;
                isTrue=isTrue|isExist(i,j,0,m,n,len,board,word,vis);
            }
        }
        return isTrue;
    }
};