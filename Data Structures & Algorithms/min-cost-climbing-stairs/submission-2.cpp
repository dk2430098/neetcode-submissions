class Solution {
    int helper(int idx, vector<int>& cost, vector<int>& dp){
       if(idx <= 1) return 0;

       if(dp[idx] != -1) return dp[idx];

       return dp[idx] = min(
        helper(idx-1, cost, dp) + cost[idx-1], helper(idx-2, cost, dp) + cost[idx-2]
       );
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);

        return helper(n, cost, dp);

    }
};
