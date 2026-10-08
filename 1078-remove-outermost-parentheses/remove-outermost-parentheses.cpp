class Solution {
public:
    string removeOuterParentheses(string s) {
        string str="";
        int o=0;
        for(char ch:s){
            if(ch=='('){
                if(o)str+=ch;
                o++;
            }
            else{
                if(o!=1)str+=ch;
                o--;
            }
        }
        return str;
    }
};