#include <gtest/gtest.h>
#include <bits/stdc++.h>

class CustomStack {
public:
    CustomStack(int maxSize)
        : m_maxSize(maxSize)
    {}

    void push(int x) {
        if(st.size() < m_maxSize)
        {
            st.push_back(x);
        }
    }
    
    int pop() {
        if(!st.size())
            return -1;
        int val = st.back();
        st.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        for(int i = 0; i < k; i++)
        {
            if(i >= st.size())
                break;
            st[i] += val;
        }
    }
private:
    int m_maxSize;
    std::vector<int> st;
};

TEST(Test, Smoke) {
    std::shared_ptr<CustomStack> stk = std::make_shared<CustomStack>(3);
    {  
        stk->push(1);                          // stack becomes [1]
        stk->push(2);                          // stack becomes [1, 2]
        ASSERT_EQ(2, stk->pop());              // return 2 --> Return top of the stack 2, stack becomes [1]
        stk->push(2);                          // stack becomes [1, 2]
        stk->push(3);                          // stack becomes [1, 2, 3]
        stk->push(4);                          // stack still [1, 2, 3], Do not add another elements as size is 4
        stk->increment(5, 100);                // stack becomes [101, 102, 103]
        stk->increment(2, 100);                // stack becomes [201, 202, 103]
        ASSERT_EQ(103, stk->pop());            // return 103 --> Return top of the stack 103, stack becomes [201, 202]
        ASSERT_EQ(202, stk->pop());            // return 202 --> Return top of the stack 202, stack becomes [201]
        ASSERT_EQ(201, stk->pop());            // return 201 --> Return top of the stack 201, stack becomes []
        ASSERT_EQ(-1, stk->pop());             // return -1 --> Stack is empty return -1.
    }
}