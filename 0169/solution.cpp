class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (m.find(nums[i]) == m.end()) {
                m[nums[i]] = 1;
            }
            else {
                m[nums[i]] += 1;
            }
        }
        map<int, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++) {
            if (it->second > len / 2) break;
        }
        return it->first;
    }
};

class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        return nums[len / 2];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            if (count == 0) {
                candidate = nums[i];
            }
            count += (nums[i] == candidate) ? 1 : -1;
        }
        return candidate;
    }
};