class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int> ahead(2*k+1,0),cur(2*k+1,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int trans=2*k-1;trans>=0;trans--){
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