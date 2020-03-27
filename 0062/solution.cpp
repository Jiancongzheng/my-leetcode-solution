class Solution1 {
public:
    int uniquePaths(int m, int n) {
        int a = m - 1;
        int b = n - 1;
        if (a == 0 or b == 0) return 1;
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};

class Solution {
public:
    int uniquePaths(int m, int n) {
        int a = (m > n) ? m : n;
        int b = (m <= n) ? (m - 1) : (n - 1);
        double sum = 1; // ！！！ double 可以表示的最大数比 int 大
        for (int i = 0; i < b; i++) {
            sum *= a + i;
            sum /= 1 + i;
        }
        return sum;
    }
};

class Solution2 {
public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) return 0;
        if (m == 1) return 1;
        if (n == 1) return 1;
        int** A = new int* [m];
        for (int i = 0; i < m; i++)
            A[i] = new int[n];
        for (int j = 0; j < n; j++)
            A[0][j] = 1;
        for (int i = 1; i < m; i++)
            A[i][0] = 1;
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                A[i][j] = A[i - 1][j] + A[i][j - 1];
        return A[m - 1][n - 1];
    }
};