class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int hash[101]={0};
            int l=0;
            for(int j=i;j<n;j++){
                hash[nums[j]]++;
                if(hash[nums[j]]==1)l++;
                ans+=l*l;
            }
        }
        return ans;
    }
};