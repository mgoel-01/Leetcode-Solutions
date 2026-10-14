class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s="";
        int temp=sum;
        int l=0;
        if(num*9<sum)return s;
        while(temp>9 && l<num){
            s+='9';
            temp-=9;
            l++;
        }
        if(temp>0 && l<num){
            s+=to_string(temp);
            temp=0;
            l++;
        }
        while(l<num){
            s+='0';
            l++;
        }
        return s;
    }
};