class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        map<int, int> m;
        for (int i = 1; i <= N; i++) {
            if (i == K) m[i] = 0;
            else m[i] = -1;
        }
        while (true) {
            bool isChanged = false;
            for (int i = 0; i < times.size(); i++) {
                if (m[times[i][0]] != -1) {
                    int currentTime = m[times[i][0]] + times[i][2];
                    if (m[times[i][1]] == -1 or currentTime < m[times[i][1]]) {
                        m[times[i][1]] = currentTime; 
                        isChanged = true;
                    }
                }
            }
            if (!isChanged) break;
        }
        int time = 0;
        for (int i = 1; i <= N; i++) {
            if (m[i] == -1) return -1;
            if (time < m[i]) time = m[i];
        }
        return time;
    }
};