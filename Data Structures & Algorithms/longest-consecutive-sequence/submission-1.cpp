class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n <= 0) return 0;
        sort(nums.begin(), nums.end());

        int i = 0, j = 1;
        int sameTime = 0;
        int maxLen = 1;

        while(j < n){
            if(nums[j] == nums[j-1]) {
                sameTime++;
                j++;
                continue;
            }
            else if(nums[j] == (nums[j-1] + 1)) {
                maxLen = max(maxLen, (j - i + 1 - sameTime));
                j++;
            }
            else {
                i = j;
                sameTime = 0;
                j++;
            }

        }

        return maxLen;
    }
};
