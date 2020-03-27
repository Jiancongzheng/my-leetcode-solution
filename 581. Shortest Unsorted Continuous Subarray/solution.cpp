class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int len = nums.size();
        int max = 0;
        int check = 0;
        int flag = 0;
        for (int i = 1; i < len; i++) {
            if (nums[i] < nums[i - 1] or nums[i] < nums[check]) {
                max = i;
                flag = 1;
                if (nums[i - 1] > nums[check]) check = i - 1;
            }
        }

        if (flag == 0) return flag;

        int min = max;
        check = max;
        for (int i = max - 1; i > -1; i--) {
            if (nums[i] > nums[i + 1] or nums[i] > nums[check]) {
                min = i;
                if (nums[i + 1] < nums[check]) check = i + 1;
            }
        }

        return max - min + 1;
    }
};