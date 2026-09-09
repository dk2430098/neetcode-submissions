class Solution {
    bool solve(int i, int j, string& s, vector<vector<int>>& dp){
        if(i >= j) return true;
        
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j]) {
            return dp[i][j] = solve(i+1, j-1, s, dp);
        }
        else return dp[i][j] = false;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxLen = 0;
        int start = -1;

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(i, j, s, dp)){
                    if(maxLen < (j-i+1)){
                        maxLen = (j-i+1);
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
