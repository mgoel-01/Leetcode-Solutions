class Solution {
public:
    void gen(string str,int n,int m,vector<string>& ans){
        if(n==m && n==0){
            ans.push_back(str);
            return;
        }
        if(n>0){
            gen(str+"(",n-1,m,ans);
        }
        if(m>0 && n<m){
            gen(str+")",n,m-1,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen("",n,n,ans);
        return ans;
    }
};