/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 */

// @lc code=start
struct Node{
    Node(int a, int b) {
        num = a;
        frq = b;
    }
    int num;
    int frq;
    
    bool operator<(const Node n) const {
        return this->frq < n.frq;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> uMap;
        for (const int& n : nums) {
            ++uMap[n];
        }
        
        priority_queue<Node> pq;
        for (auto p : uMap) {
            Node n(p.first, p.second);
            pq.push(n);
        }
        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.emplace_back(pq.top().num);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end

