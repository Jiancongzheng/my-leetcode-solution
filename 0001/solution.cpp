class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> m;
        int len = nums.size();
        int complement;
        vector<int> indices = {0,0};
        for (int i = 0; i < len; i++) {
            complement = target - nums[i];
            if (m.find(complement) != m.end()) {
                indices[0] = m[complement];
                indices[1] = i;
                return indices;
            }
            else {
                m[nums[i]] = i;
            }
        }
        return indices;
    }
};