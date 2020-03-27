class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        if (s.size() % 2 != 0) {
            return false;
        }
        for (auto i : s) {
            switch (i) {
            case '(':
                stack.push(i);
                break;
            case '[':
                stack.push(i);
                break;
            case '{':
                stack.push(i);
                break;
            case ')':
                if (!stack.empty()) {
                    if (stack.top() == '(') {
                        stack.pop();
                        break;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            case ']':
                if (!stack.empty()) {
                    if (stack.top() == '[') {
                        stack.pop();
                        break;
                    }
                    else return false;
                }
                else return false;
            case '}':
                if (!stack.empty()) {
                    if (stack.top() == '{') {
                        stack.pop();
                        break;
                    }
                    else return false;
                }
                else return false;
            }
        }
        if (stack.empty()) return true;
        else return false;
    }
};