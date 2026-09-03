class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       int minOdd=INT_MAX;
       for(auto x:nums1){
            if(x%2!=0 && minOdd>x)minOdd=x;
       } 
       bool isUniform=true;
       for(auto x:nums1){
            if(x%2==0){
                if((x-minOdd)<1)isUniform=false;
            }
       }
       if(isUniform)return true;
       for(auto x:nums1){
            if(x%2!=0){
               if((x-minOdd)<1)return false;
            }
       }
       return true;
    }
};