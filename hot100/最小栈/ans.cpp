class MinStack {
public:
    MinStack() {
        // 初始化时不需要做任何操作
    }
    
    void push(int val) {
        nums.push_back(val);
        if (val < min) {
            min = val;
        }
        // 为了支持 O(1) 时间复杂度的 getMin 操作，我们使用一个辅助栈来存储最小值
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (nums.empty()) {
            return; // 如果栈为空，直接返回
        }
        if (nums.back() == minStack.top()) {
            minStack.pop(); // 如果弹出的元素是当前最小值，更新最小值栈
        }
        nums.pop_back();
        // 更新 min 的值
        if (!minStack.empty()) {
            min = minStack.top();
        } else {
            min = INT_MAX; // 如果栈为空，将 min 重置为 INT_MAX
        }
    }
    
    int top() {
        if (nums.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return nums.back();
    }
    
    int getMin() {
        if (minStack.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return minStack.top();
    }

private:
    std::vector<int> nums; // 存储栈中的元素
    int min = INT_MAX; // 当前栈中的最小值
    std::stack<int> minStack; // 辅助栈，用于存储最小值
};
/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */