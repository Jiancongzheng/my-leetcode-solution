class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        int len = nums.size();
        vector<int> tmp;
        output.push_back(tmp);
        for (int i = 0; i < len; i++) {
            int outLen = output.size();
            for (int j = 0; j < outLen; j++) {
                vector<int> tmp1;
                tmp1 = output[j];
                tmp1.push_back(nums[i]);
                output.push_back(tmp1);
            }
        }
        return output;
    }
};