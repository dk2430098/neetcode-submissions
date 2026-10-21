class Solution {
public:
    bool check(string& str){
        if(str.empty() || str[0] == '0') return false;
        return stoi(str) >= 1 && stoi(str) <= 26;
    }
    int f(int idx, int n, string& s, vector<int>& dp){
        if(idx == n) return 1;
        if(s[idx] == '0') return 0;

        if(dp[idx] != -1) return dp[idx];
        int count = 0;
        count += f(idx+1, n, s, dp);
        if(idx + 1 < n){
            string str = s.substr(idx, 2);

            if(check(str)) count += f(idx+2, n, s, dp);
        }

        return dp[idx] = count;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);

        return f(0, n, s, dp);
    }
};
