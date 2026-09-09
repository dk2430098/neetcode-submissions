class Solution {
    bool solve(int i, int j, string& s, vector<vector<int>>& dp){
        if(i >= j) return true;

        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = solve(i+1, j-1, s, dp);
        else return dp[i][j] = false;
    }
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        int count = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(solve(i, j, s, dp)) count++;
            }
        }

        return count;
    }
};
