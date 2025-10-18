class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>pre(prices.size(),0);
        int mmax = 0;
        for(int i = prices.size()-1; i >= 0 ; --i){
            mmax = max(prices[i],mmax);
            pre[i]=mmax;
        }
        int ans = 0;
        for(int i = 0; i < prices.size(); ++i){
            ans = max(ans, pre[i]-prices[i]);
        }
        return ans;
    }
};