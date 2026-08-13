class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp; // {val, freq}

        for(int x : nums){
            if(mp.find(x) != mp.end()) return true;
            mp[x]++;
        }

        return false;
    }
};