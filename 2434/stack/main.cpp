#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::string robotWithString(std::string s) {
        std::map<char, int> mp;
        std::stack<char> st;

        for(auto c : s)
            mp[c]++;

        std::string res;
        for(auto c : s)
        {
            if(c == mp.begin()->first)
            {
                res += c;
                if(--mp.begin()->second == 0)
                    mp.erase(mp.begin());

                while(!st.empty() && st.top() <= mp.begin()->first)
                {
                    res += st.top();
                    st.pop();
                }
            }
            else
            {
                auto it = mp.find(c);
                if(--it->second == 0)
                    mp.erase(it);
                st.push(c);
            }
        }

        while(!st.empty())
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ("fnohopzv", obj->robotWithString("vzhofnpo"));
        ASSERT_EQ("azz", obj->robotWithString("zza"));
        ASSERT_EQ("abc", obj->robotWithString("bac"));
        ASSERT_EQ("addb", obj->robotWithString("bdda"));
        ASSERT_EQ("bdevfziy", obj->robotWithString("bydizfve"));     
        ASSERT_EQ("biknqrw", obj->robotWithString("binkrqw"));
    }
}
