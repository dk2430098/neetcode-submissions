class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<vector<int>> ans;

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Since array is sorted, no solution is possible
            if (nums[i] > 0)
                break;

            int target = -nums[i];
            int low = i + 1;
            int high = n - 1;

            while (low < high) {
                int sum = nums[low] + nums[high];

                if (sum == target) {
                    ans.push_back({
                        nums[i],
                        nums[low],
                        nums[high]
                    });

                    // Skip duplicate left values
                    while (low < high && nums[low] == nums[low + 1])
                        low++;

                    // Skip duplicate right values
                    while (low < high && nums[high] == nums[high - 1])
                        high--;

                    low++;
                    high--;
                }
                else if (sum > target) {
                    high--;
                }
                else {
                    low++;
                }
            }
        }

        return ans;
    }
};