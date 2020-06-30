class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(int i = 0; i < tasks.size(); i++) {
            count[tasks[i] - 'A'] += 1;
        }
        sort(count.begin(), count.end(), greater<int>());
        int num = (count[0] - 1) * (n + 1) + 1;
        int idle = (count[0] - 1) * n;
        int i = 1;
        while(i < 26) {
            if (count[i] == 0) return num;
            if (count[i] == count[0]) {
                num += 1;
                idle += 1;
            }
            idle -= count[i];
            i++;
            if (idle <= 0) {
                num -= idle;
                break;
            }
            
        }
        if (tasks.size() < num) return num;
        else return tasks.size();
    }
};