class Solution {
    int f(int idx, int n, int amount, vector<int>& coins, vector<vector<int>>& dp){
        if(amount == 0) return 0;
        if(amount < 0 || idx == n) return INT_MAX;

        if(dp[idx][amount] != -1) return dp[idx][amount];
        int val = INT_MAX;
        for(int i = idx; i < n; i++){
            int ans = f(i, n, amount - coins[i], coins, dp);

            if(ans != INT_MAX){
                val = min(val, 1 + ans);
            }
        }
        return dp[idx][amount] = val;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));

        int ans = f(0, n, amount, coins, dp);
        return (ans != INT_MAX) ? ans : -1;
    }
};
