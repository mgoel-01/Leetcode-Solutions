class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        bool cons=false;
        int ans=0;
        for(char c:s){
            if(c=='('){
                if(cons){
                    ans++;
                    cons=false;
                    if (!st.empty()) st.pop();
                }
                st.push('(');
                st.push('(');
            }
            else{
                if(!st.empty()){
                    if(cons)cons=false;
                    else cons=true;
                    st.pop();
                }
                else{
                    if(cons){
                        cons=false;
                    }
                    else {
                        ans++;
                        cons=true;
                    }
                }
            }
        }
        return ans+st.size()+(cons && st.empty() ? 1 : 0);
    }
};