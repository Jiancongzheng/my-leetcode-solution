class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> lists;
        int len = nums.size();
        for (int i = 0; i < len - 2; i++) {
            if (nums[i] > 0) return lists;
            if (i > 0 and nums[i] == nums[i - 1]) continue;
            int target = 0 - nums[i];
            int j = i + 1;
            int k = len - 1;
            while (true) {
                if (nums[j] + nums[k] == target) {
                    lists.push_back({ nums[i], nums[j], nums[k] });
                }
                if (nums[j] == nums[k]) break;
                if (nums[j] + nums[k] < target) {
                    int current = nums[j];
                    while (nums[j] == current and j != k) {
                        j++;
                    }
                }
                else {
                    int current = nums[k];
                    while (nums[k] == current and j != k) {
                        k--;
                    }
                }
                if (j == k or nums[j] > target) break;
            }
        }
        return lists;
    }
};