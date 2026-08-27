class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++){
            int newTarget = target - numbers[i];
            if(mp.find(newTarget) != mp.end()){
                return {min(i+1, mp[newTarget]+1), max(i+1, mp[newTarget]+1)};
            }
            mp[numbers[i]] = i;
        }

        return {-1,-1};
    }
};
