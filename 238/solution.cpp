class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> R;
        R.push_back(1);
        int mul = 1;
        int len = nums.size();
        for (int i = 0; i < len - 1; i++) {
            mul *= nums[i];
            R.push_back(mul);
        }
        mul = 1;
        for (int i = len - 1; i >= 0; i--) {
            R[i] *= mul;
            mul *= nums[i];
        }
        return R;
    }
};