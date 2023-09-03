#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        std::unordered_map<char, int> mp;
        std::unordered_map<char, int> visited;

        for(auto c : s)
            mp[c]++;
        
        std::string res;

        for(auto c : s)
        {
            mp[c]--;
            if(visited[c] == 1)
            {
                continue;
            }

            while(res.size() > 0)
            {
                if(res.back() > c && mp[res.back()] > 0)
                {
                    visited[res.back()] = 0;
                    res.pop_back();
                }
                else
                    break;             
            }
            res += c;
            visited[c] = 1;
        }
        return res;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        ASSERT_EQ("abc", obj->removeDuplicateLetters("bcabc"));
    }
    {
        ASSERT_EQ("acdb", obj->removeDuplicateLetters("cbacdcbc"));
    }
    {
        ASSERT_EQ("adbc", obj->removeDuplicateLetters("cdadabcc"));
    }
    {
        ASSERT_EQ("bed", obj->removeDuplicateLetters("edebbed"));
    }
}