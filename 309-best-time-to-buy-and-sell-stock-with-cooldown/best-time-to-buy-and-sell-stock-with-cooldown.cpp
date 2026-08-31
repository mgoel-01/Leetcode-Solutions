class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> after(2,0),afterafter(2,0),cur(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit=max(-prices[ind]+after[0],after[1]);
                }
                else{
                    profit=max(prices[ind]+afterafter[1],after[0]);
                }
                cur[buy]=profit;
            }
            afterafter=after;
            after=cur;
        }
        return after[1];
    }
};