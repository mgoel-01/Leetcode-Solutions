class Solution {
public:
    bool isValid(string s){
        stack<char> st;
        for(char c:s){
            if(c=='(')st.push(c);
            else if(c==')'){
                if(st.empty() || st.top()!='(')return false;
                else st.pop();
            }
        }
        return st.empty();
    }
    int mini=INT_MAX;
    void validPar(string s,int n,int r,unordered_set<string>& vis,set<string>& ans){
        if(vis.count(s))return;
        else vis.insert(s);
        if(r>mini)return;
        if(r==mini){
            if(isValid(s))ans.insert(s);
            return;
        }
        for(int j=0;j<n;j++){
            if(j > 0 && s[j] == s[j-1])continue;
            string str=s.substr(0,j)+s.substr(j+1);
            validPar(str,n-1,r+1,vis,ans);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> vis;
        int o=0,cl=0;
        for(char c:s){
            if(c=='(')o++;
            else if(c==')'){
                if(o)o--;
                else cl++;
            }
        }
        mini=o+cl;
        set<string> ans;
        validPar(s,s.size(),0,vis,ans);
        vector<string> res(ans.begin(),ans.end());
        return res;
    }
};