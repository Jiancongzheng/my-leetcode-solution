class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum, min, res;
        res = nums[0];
        min = 0;
        sum = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            sum += nums[i];
            res = (sum - min > res) ? sum - min : res;
            min = (sum < min) ? sum : min;
        }
        return res;
    }
};