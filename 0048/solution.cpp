class Solution1 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                matrix[j].push_back(matrix[i][j]);
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                matrix[i].erase(matrix[i].begin());
            }
        }
    }
};

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

