class Solution {
public:
    int digiSum(int n){
        int sum=0;
        while(n){
            sum+=n%10;
            n/=10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(digiSum(nums[i])==i)return i;
        }
        return -1;
    }
};