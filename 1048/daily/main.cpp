#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int longestStrChain(std::vector<std::string>& words) {
        sort(words.begin(), words.end(),
        [](const std::string& s1, const std::string& s2){
            return s1.size() < s2.size();
        });

        std::unordered_map<std::string, int> mp;
        int res = 0;
        for(const auto word : words)
        {
            int len = 0;
            for(int i = 0; i < word.size(); i++)
            {
                std::string tmp = word;
                tmp.erase(i, 1);

                len = std::max(len, mp[tmp] + 1);
            }
            mp[word] = len;
            res = std::max(len, res);
        }

        return res;
    }
}; 

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<std::string> input{"a","b","ba","bca","bda","bdca"};
        ASSERT_EQ(4, obj->longestStrChain(input));
    }

}
