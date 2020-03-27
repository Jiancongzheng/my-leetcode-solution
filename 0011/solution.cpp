class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int result = 0;
        while (i != j) {
            int area = ((height[i] > height[j]) ? height[j] : height[i])* (j - i);
            if (area > result) result = area;
            if (height[i] < height[j]) i++;
            else j--;
        }
        return result;
    }
};