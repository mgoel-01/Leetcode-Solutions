class Solution {
public:
    bool detectCycle(int node,vector<int>& vis,vector<int>& dfsVis,vector<vector<int>>& graph){
        vis[node]=1;
        dfsVis[node]=1;
        for(auto it:graph[node]){
            if(!vis[it]){
                if(detectCycle(it,vis,dfsVis,graph))return true;
            }
            else if(dfsVis[it])return true;
        }
        dfsVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0),dfsVis(n,0);
        vector<int> ans;
        for(int i=0;i<n;i++){
                if(!detectCycle(i,vis,dfsVis,graph)){
                    ans.push_back(i);
                }
        }
        return ans;
    }
};