#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int GetSubdirLevel(const std::string& input, int& pos)
    {
        int tabs = 0;

        while(pos < input.size() && input[pos] == '\t')
        {
            pos++;
            tabs++;
        }
        return tabs;
    }

    bool IsFile(const std::string& input)
    {
        return input.find('.') != std::string::npos;
    }
    
    int GetCurrentLen(const std::unordered_map<int, std::string>& mp, int current_level)
    {
        int cur_len = 0;
        for(int i = 0; i <= current_level; i++)
        {
            cur_len += mp.at(i).size();
        }
        return cur_len + current_level;
    }

    int lengthLongestPath(std::string input) {
        int max_len = 0;

        std::unordered_map<int, std::string> mp;

        std::string tmp;

        int pos = 0;
        int current_level = 0;
        while(pos < input.size())
        {
            char c = input[pos];
            if(c != '\n')
            {
                tmp += c;
                pos++;
            }
            else
            {
                mp[current_level] = tmp;
                pos++;
                int tabs = GetSubdirLevel(input, pos);

                if(IsFile(tmp))
                {
                    max_len = std::max(max_len, GetCurrentLen(mp, current_level));
                }
                current_level = tabs;
                tmp.clear();
            }
        }
        if(IsFile(tmp))
        {
            mp[current_level] = tmp;
            max_len = std::max(max_len, GetCurrentLen(mp, current_level));
        }

        return max_len;
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    /*{
        ASSERT_EQ(20, obj->lengthLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"));
    }*/
    {
        ASSERT_EQ(8, obj->lengthLongestPath("a.tar.gz"));
    }
}
