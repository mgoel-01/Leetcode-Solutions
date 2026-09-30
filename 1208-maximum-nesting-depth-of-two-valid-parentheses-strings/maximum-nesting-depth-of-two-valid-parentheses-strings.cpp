class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int c1=0;
        int c2=0;
        int n=seq.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                c1++;
                if(c1%2==1)ans[i]=0;
                else ans[i]=1;
            }
            else{
                if(c1%2==0)ans[i]=1;
                else ans[i]=0;
                c1--;
            }
        }
        return ans;
    }
};