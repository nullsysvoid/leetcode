#include <gtest/gtest.h>
#include <bits/stdc++.h>

class StockSpanner {
    struct Day
    {
        int value;
        int prevTotal;
    };
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        while(!st.empty() && st.top().value <= price)
        {
            res += st.top().prevTotal;
            st.pop();
        }
        st.push({price, res});
        return res;
    }
private:
    std::stack<Day> st;
};

TEST(Test, Smoke) {
    std::shared_ptr<StockSpanner> obj = std::make_shared<StockSpanner>();
    
    
    ASSERT_EQ(1, obj->next(100)); // return 1
    ASSERT_EQ(1, obj->next(80));  // return 1
    ASSERT_EQ(1, obj->next(60));  // return 1
    ASSERT_EQ(2, obj->next(70));  // return 2
    ASSERT_EQ(1, obj->next(60));  // return 1
    ASSERT_EQ(4, obj->next(75));  // return 4, because the last 4 prices (including today's price of 75) were less than or equal to today's price.
    ASSERT_EQ(6, obj->next(85));  // return 6
}
