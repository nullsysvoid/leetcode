#include <gtest/gtest.h>
#include <bits/stdc++.h>

class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int val = peek();
        st2.pop();

        return val;
    }
    
    int peek() {
        if(st2.empty())
        {
            while(!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
        }
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }
private:
    std::stack<int> st1, st2;
};

TEST(Test, Smoke) {
    std::shared_ptr<MyQueue> obj = std::make_shared<MyQueue>();
    {
        //["MyQueue", "push", "push", "peek", "pop", "empty"]
        //[[], [1], [2], [], [], []]
        MyQueue* obj = new MyQueue();
        obj->push(1);
        obj->push(2);
        ASSERT_EQ(1, obj->peek());
        ASSERT_EQ(1, obj->pop());
        ASSERT_FALSE(obj->empty());
    }
}
