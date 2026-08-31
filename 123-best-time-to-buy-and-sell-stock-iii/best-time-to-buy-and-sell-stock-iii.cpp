class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> ahead(5,0),cur(5,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int trans=3;trans>=0;trans--){
                int profit=0;
                if(trans%2==0){
                    profit=max(-prices[ind]+ahead[trans+1],ahead[trans]);
                }
                else{
                    profit=max(prices[ind]+ahead[trans+1],ahead[trans]);
                }
                cur[trans]=profit;
            }
            ahead=cur;
        }
        return ahead[0];
    }
};