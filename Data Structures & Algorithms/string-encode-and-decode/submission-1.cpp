class Solution {
public:
    string encode(vector<string>& strs) {
        string ans = "";

        for (string str : strs) {
            ans += to_string(str.size()) + "#" + str;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i = 0;

        while (i < s.size()) {
            int j = i;

            // Find the delimiter after the length
            while (s[j] != '#') {
                j++;
            }

            int len = stoi(s.substr(i, j - i));

            // Extract exactly 'len' characters
            ans.push_back(s.substr(j + 1, len));

            i = j + 1 + len;
        }

        return ans;
    }
};