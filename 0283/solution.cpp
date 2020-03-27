class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        vector<int>::iterator i;
        int num = 0;
        for (i = nums.begin(); i != nums.end(); i++) {
            if (*i == 0) {
                nums.erase(i);
                num++;
                i--;
            }
        }
        for (int i = 0; i < num; i++) nums.push_back(0);
    }
};