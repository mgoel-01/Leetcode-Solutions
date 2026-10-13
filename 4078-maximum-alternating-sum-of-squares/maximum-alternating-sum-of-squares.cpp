class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        sort(nums.begin(),nums.end(),[](int a,int b){
            return abs(a)<abs(b);
        });
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i>=n/2)ans+=(1LL*nums[i]*nums[i]);
            else ans-=(1LL*nums[i]*nums[i]);
        }
        return ans;
    }
};