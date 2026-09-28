class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;
        int maxi=0;
        for(auto c: s){
            if(c=='(')cnt++;
            if(c==')')cnt--;
            if(maxi<=cnt){
                maxi=cnt;
            }
        }
        return maxi;
    }
};