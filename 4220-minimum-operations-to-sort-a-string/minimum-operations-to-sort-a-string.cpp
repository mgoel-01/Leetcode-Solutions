class Solution {
public:
    int minOperations(string s) {
        int mini=s[0]-'a';
        int maxi=s[0]-'a';
        bool sorted=true;
        int n=s.size();
        for(int i=1;i<n;i++){
            char val=s[i]-'a';
            if(val<mini)mini=val;
            if(val>maxi)maxi=val;
            if(val<maxi)sorted=false;
        }
        if(sorted)return 0;
        if(mini==s[0]-'a' || maxi==s[n-1]-'a')return 1;
        if(n==2 && maxi==s[0]-'a' && mini==s[1]-'a')return -1;
        if(mini==s[n-1]-'a' && maxi==s[0]-'a' && count(s.begin(),s.end(),'a'+mini)==1 &&
        count(s.begin(),s.end(),'a'+maxi)==1)return 3;
        return 2;
    }
};