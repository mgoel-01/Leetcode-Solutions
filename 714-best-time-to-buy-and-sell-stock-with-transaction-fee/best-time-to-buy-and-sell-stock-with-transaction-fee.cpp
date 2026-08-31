class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> after(2,0),cur(2,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy){
                    profit=max(-prices[ind]-fee+after[0],after[1]);
                }
                else{
                    profit=max(prices[ind]+after[1],after[0]);
                }
                cur[buy]=profit;
            }
            after=cur;
        }
        return after[1];
    }
};