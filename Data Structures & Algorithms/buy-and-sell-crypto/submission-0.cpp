class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int mn = INT_MAX;

        for(int price : prices){
            mn = min(mn, price);
            ans = max(ans, price - mn);
        }

        return ans;
    }
};
