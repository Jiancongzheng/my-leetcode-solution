/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> ans;
        
        if(nums.empty())
            return ans;
        int n= nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i=0; i<n-3; i++) {
            for(int j=i+1; j<n-2; j++) {
                
                int new_target= target-nums[i]-nums[j];
                int left=j+1, right= n-1;
                
                while(left < right) {
                    int sum= nums[left]+nums[right];
                    
                    if(sum < new_target) left++;
                    
                    else if(sum > new_target) right--;
                    
                    else {
                        vector<int> temp(4,0);
                        temp[0]= nums[i];
                        temp[1]= nums[j];
                        temp[2]= nums[left];
                        temp[3]= nums[right];
                        ans.push_back(temp);
                        
                        while(left < right && nums[left]== temp[2]) left++;
                        while(left < right && nums[right]== temp[3]) right--;
                    }
                }
                while(j+1<n && nums[j+1]== nums[j]) j++;
            }
            while(i+1<n && nums[i+1]== nums[i]) i++;
        }
        
        return ans;
    }
};
// @lc code=end

