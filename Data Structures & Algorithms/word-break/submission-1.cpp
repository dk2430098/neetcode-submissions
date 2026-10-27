class Solution {
    bool f(int idx, string& s, vector<string>& w,
           vector<int>& dp) {

        if (idx == s.size())
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        for (int i = 0; i < w.size(); i++) {
            int len = w[i].size();

            if (idx + len <= s.size() &&
                s.compare(idx, len, w[i]) == 0) {

                if (f(idx + len, s, w, dp))
                    return dp[idx] = 1;
            }
        }

        return dp[idx] = 0;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return f(0, s, wordDict, dp);
    }
};