#include <gtest/gtest.h>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    std::string decodeAtIndex(std::string s, int k) {
        long long cnt = 0;
        std::stack<char> st;
        for(auto c : s)
        {
            if(isdigit(c))
                cnt *= (c - '0');
            else
                cnt++;
            st.push(c);
            if(cnt >= k)
                break;
        }
        while(!st.empty())
        {
            char c = st.top();
            if(isdigit(c))
            {
                cnt /= (c - '0');
                k %= cnt;
            }
            else
            {
                if(k % cnt == 0)
                    break;
                cnt--;
            }
            st.pop();
        }
            
        std::string res = std::string(1, st.top());
        return res;  
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    ASSERT_EQ("o", obj->decodeAtIndex("leet2code3", 10));
    ASSERT_EQ("h", obj->decodeAtIndex("ha22", 5));
    ASSERT_EQ("a", obj->decodeAtIndex("a23", 6));
    ASSERT_EQ("c", obj->decodeAtIndex("czjkk9elaqwiz7s6kgvl4gjixan3ky7jfdg3kyop3husw3fm289thisef8blt7a7zr5v5lhxqpntenvxnmlq7l34ay3jaayikjps", 768077956));
    
}