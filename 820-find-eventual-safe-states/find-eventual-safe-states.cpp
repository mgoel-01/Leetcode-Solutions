class Solution {
public:
    bool detectCycle(int node,vector<int>& vis,vector<int>& dfsVis,vector<vector<int>>& graph,vector<int>& temp){
        vis[node]=1;
        dfsVis[node]=1;
        temp.push_back(node);
        for(auto it:graph[node]){
            if(!vis[it]){
                if(detectCycle(it,vis,dfsVis,graph,temp))return true;
            }
            else if(dfsVis[it])return true;
        }
        dfsVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        set<int> st;
        vector<int> vis(n,0),dfsVis(n,0);
        for(int i=0;i<n;i++){
                vector<int> temp;
                if(!detectCycle(i,vis,dfsVis,graph,temp)){
                    for(auto x:temp)st.insert(x);
                }
        }
        vector<int> ans(st.begin(),st.end());
        return ans;
    }
};