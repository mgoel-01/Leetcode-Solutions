class Solution {
public:
    long long power(long long n,int dig){
        while(dig>1){
            n*=1LL*10;
            dig--;
        }
        return n;
    }
    long long countCommas(long long n) {
        if(n<1000)return 0;
        long long cnt=0;
        int dig = 0;
        long long temp=n;
        while (temp) {
            dig++;
            temp /= 10;
        }
        if(dig>3&&dig<7)dig=4;
        else if(dig>6 && dig<10)dig=7;
        else if(dig>9 && dig<13)dig=10;
        else if(dig>12 && dig<16)dig=13;
        else if(dig>15 && dig<19)dig=16;
        else dig=19;
        int x=dig/3;
        while(x){
            cnt+=x*(n-power(10,dig-1)+1);
            n=power(10,dig-1)-1;
            dig-=3;
            x=dig/3;
        }
        return cnt;
    }
};