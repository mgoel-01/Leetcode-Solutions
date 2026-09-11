class Solution {
public:
    bool isOpening(char c){
        return (c=='('||c=='['||c=='{');
    }
    char closing(char c){
        if(c=='(') return ')';
        else if(c=='[') return ']';
        return '}';
    }
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(isOpening(s[i]))st.push(s[i]);
            else{
                if(st.empty())return false;
                if(s[i]!=closing(st.top()))return false;
                else st.pop();
            }
        }
        if(st.empty())return true;
        return false;
    }
};