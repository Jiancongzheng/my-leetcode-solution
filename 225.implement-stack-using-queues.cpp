/*
 * @lc app=leetcode id=225 lang=cpp
 *
 * [225] Implement Stack using Queues
 */

// @lc code=start
class MyStack {
private:
    queue<int> q1;

public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        queue<int> q2;
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int n = q1.front();
        this->q1.pop();
        return n;
    }
    
    /** Get the top element. */
    int top() {
        return this->q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return this->q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

