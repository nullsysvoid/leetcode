#include <gtest/gtest.h>
#include <bits/stdc++.h>

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if(!m_minSt.empty() && val <= m_minSt.top())
        {
            m_minSt.push(val);
        }
        else if (m_minSt.empty())
            m_minSt.push(val);
        m_curSt.push(val);
    }
    
    void pop() {
        if(!m_curSt.empty() && !m_minSt.empty() && (m_curSt.top() == m_minSt.top()))
        {
            m_minSt.pop();
        }
        if(!m_curSt.empty())
        {
            m_curSt.pop();
        }
    }
    
    int top() {
        return m_curSt.top();
    }
    
    int getMin() {
        return m_minSt.top();
    }
private:
    std::stack<int> m_minSt;
    std::stack<int> m_curSt;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

TEST(Test, Smoke) {
    std::shared_ptr<MinStack> minStack = std::make_shared<MinStack>();

    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    
    ASSERT_EQ(-3, minStack->getMin());
    minStack->pop();
    ASSERT_EQ(0, minStack->top());
    ASSERT_EQ(-2, minStack->getMin());



}