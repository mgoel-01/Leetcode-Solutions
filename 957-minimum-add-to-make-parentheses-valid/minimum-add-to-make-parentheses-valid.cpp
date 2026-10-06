class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(')st.push('(');
            else{
                if(!st.empty() && st.top()=='(')st.pop();
                else if(st.empty() || st.top()==')'){
                    st.push(')');
                }
            }
        }
        return st.size();
    }
};