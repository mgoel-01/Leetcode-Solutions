class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> st;
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int i=0;
        int j=0;
        int n=nums1.size();
        int m=nums2.size();
        while(i<n && j<m){
            if(nums1[i]==nums2[j]){
                st.insert(nums1[i]);
                i++;
                j++;
                continue;
            }
            while(j<m && nums1[i]>nums2[j]){
                j++;
                continue;
            }
            while(i<n && j<m && nums1[i]<nums2[j]){
                i++;
                continue;
            }
        }
        vector<int> ans(st.begin(),st.end());
        return ans;
    }
};