class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int> mp; // {val, index}

        for(int i = 0; i < n; i++){
            int newTarget = target - nums[i];
            if(mp.find(newTarget) != mp.end()){
                return {mp[newTarget], i};
            }
            mp[nums[i]] = i;
        }

        return {-1, -1};
    }
};
