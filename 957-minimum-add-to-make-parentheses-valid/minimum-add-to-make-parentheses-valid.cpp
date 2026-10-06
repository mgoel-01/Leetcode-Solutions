class Solution {
public:
    int minAddToMakeValid(string s) {
        int o=0;
        int c=0;
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(')o++;
            else {
                if(o>0)o--;
                else ans++;
            }
        }
        return ans+o;
    }
};