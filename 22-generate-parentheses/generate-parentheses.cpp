class Solution {
public:
    void gen(string& str,int n,int m,vector<string>& ans){
        if(n==m && n==0){
            ans.push_back(str);
            return;
        }
        if(n>0){
            str.push_back('(');
            gen(str,n-1,m,ans);
            str.pop_back();
        }
        if(n<m){
            str.push_back(')');
            gen(str,n,m-1,ans);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str;
        gen(str,n,n,ans);
        return ans;
    }
};