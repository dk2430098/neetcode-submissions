class Solution {
    int f(int idx, int pre, int n, vector<int>& nums, vector<vector<int>>& dp){
        if(idx == n) return 0;

        if(dp[idx][pre] != -1) return dp[idx][pre];
        // take
        int take = 0;
        if(pre == 0 || nums[idx] > nums[pre-1])
            take = 1 + f(idx+1, idx+1, n, nums, dp);
        // not_take
        int not_take = f(idx + 1, pre, n, nums, dp);

        return dp[idx][pre] = max(take, not_take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));

        return f(0, 0, n, nums, dp);
    }
};
