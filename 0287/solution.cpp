class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int i = nums[0];
        int j = nums[0];
        while (true) {
            i = nums[i];
            j = nums[nums[j]];
            if (j == i) break;
        }
        j = nums[0];
        while (true) {
            if (j == i) break;
            i = nums[i];
            j = nums[j];
        }
        return i;
    }
};

class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1;
        int right = nums.size();
        while (left != right) {
            int count = 0;
            int mid = (right - left) / 2 + left;
            for (int i = 0; i <= nums.size() - 1; i++) {
                if (nums[i] <= mid) count++;
            }
            if (count > mid) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};