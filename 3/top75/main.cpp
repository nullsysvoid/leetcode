#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if(s.size() <= 1)
            return s.size();

        std::unordered_map<char, int> mp;

        int l = 0;
        int r = 1;
        int max_res = 1;
        mp[s[0]]++;

        while(r < s.size())
        {
            char c = s[r];
            mp[c]++;
            while(l < r && mp[c] > 1)
            {
                mp[s[l]]--;
                l++;
            }
            max_res = std::max(max_res, r - l + 1);
            r++;
        }

        return max_res;
    }
};
TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        EXPECT_EQ(obj->lengthOfLongestSubstring("abcabcbb"), 3);
    }
}
