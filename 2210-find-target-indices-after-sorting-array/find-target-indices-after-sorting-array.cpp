class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> ans;
        int low=0;
        int n=nums.size();
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]<target)low=mid+1;
            else if(nums[mid]>target)high=mid-1;
            else{
                ans.push_back(mid);
                if(mid!=0){
                    int s1=mid-1;
                    while(s1>=0 && nums[s1]==target){
                        ans.push_back(s1);
                        s1--;
                    }
                }
                if(mid!=n-1){
                    int s1=mid+1;
                    while(s1<n && nums[s1]==target){
                        ans.push_back(s1);
                        s1++;
                    }
                }
                break;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};