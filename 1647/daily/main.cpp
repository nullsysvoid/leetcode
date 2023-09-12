#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils/utils.h>

class Solution {
public:
    int minDeletions(std::string s) {
        std::unordered_map<char, int> mp;
        std::set<int> st;

        for(auto c : s)
            mp[c]++;

        int res = 0;
        for(auto i : mp)
        {
            int tmp = i.second;
            while(tmp)
            {
                auto it = st.find(tmp);
                if(it == st.end())
                {
                    st.insert(tmp);
                    break;
                }
                else
                    res++;
                tmp--;
            }
        }

        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ(0, obj->minDeletions("aab"));
        ASSERT_EQ(2, obj->minDeletions("aaabbbcc"));
    }
}
