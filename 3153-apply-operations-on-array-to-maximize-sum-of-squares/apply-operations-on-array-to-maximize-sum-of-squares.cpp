class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        int mod=1e9+7;
        vector<int> setBit(31,0);
        int n=nums.size();
        for(int i=0;i<n;i++){
            int ind=0;
            while(ind<31){
                int bit=(nums[i]>>ind)&1;
                if(bit)setBit[ind]++;
                ind++;
            }
        }
        long long ans=0;
        while(k--){
            long long x=0;
            for(int i=0;i<31;i++){
                if(setBit[i]>0){
                    x+=pow(2,i);
                    setBit[i]-=1;
                }
            }
            ans=(ans+(x*x)%mod)%mod;
        }
        return (int)ans;
    }
};