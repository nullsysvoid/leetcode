#include <gtest/gtest.h>
#include <bits/stdc++.h>

class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        for(int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
private:
    std::queue<int> q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

TEST(Test, Smoke) {
    std::shared_ptr<MyStack> obj = std::make_shared<MyStack>();
    obj->push(1);
    ASSERT_EQ(obj->top(), 1);

    obj->push(2);
    ASSERT_EQ(obj->top(), 2);

    obj->pop();
    ASSERT_EQ(obj->top(), 1);

    obj->pop();
    ASSERT_TRUE(obj->empty());
}
