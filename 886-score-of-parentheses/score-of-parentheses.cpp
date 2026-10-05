class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans=0;
        int n=s.size();
        int sc=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')sc++;
            else{
                sc--;
                if(s[i-1]=='('){
                    ans+=pow(2,sc);
                }
            }
        }
        return ans;
    }
};