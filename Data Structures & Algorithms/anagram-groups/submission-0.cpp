class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for(auto& str : strs){
            string base = str;
            sort(base.begin(), base.end());
            mp[base].push_back(str);
        }

        for(auto& [str, v] : mp){
            ans.push_back(v);
        }

        return ans;
    }
};
