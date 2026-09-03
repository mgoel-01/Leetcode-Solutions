class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
       int minOdd=INT_MAX;
       for(auto x:nums1){
            if(x%2!=0 && minOdd>x)minOdd=x;
       } 
       bool isOdd=true;
       bool isEven=true;
       for(auto x:nums1){
            if(x%2==0){
                if((x-minOdd)<1)isOdd=false;
            }
            else{
                if((x-minOdd)<1)isEven= false;
            }
       }
       return isOdd|isEven;
    }
};