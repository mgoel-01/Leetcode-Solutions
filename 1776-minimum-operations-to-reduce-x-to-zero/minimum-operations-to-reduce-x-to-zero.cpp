class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        long long tar=-x;
        for(auto it:nums)tar+=it;
        if(tar==0)return n;
        unordered_map<long long,int> preSum;
        long long sum=0;
        int maxi=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==tar)maxi=max(maxi,i+1);
            long long rem=sum-tar;
            if(preSum.find(rem)!=preSum.end()){
                int len=i-preSum[rem];
                maxi=max(maxi,len);
            }
            if(preSum.find(sum)==preSum.end()){
                preSum[sum]=i;
            }
        }
        return  (maxi==-1)?-1:n-maxi;
    }
};