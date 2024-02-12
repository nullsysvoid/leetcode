#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        if(n == 0)
            return tasks.size();

        std::unordered_map<char, int> mp;
        for(const auto& task : tasks)
        {
            mp[task]++;
        }

        std::priority_queue<int> q;
        for(const auto& task : mp)
        {
            q.push(task.second);
        }

        int res = 0;
        while(!q.empty())
        {
            int len = q.size();
            if(len == 1)
            {
                res += q.top() + (q.top() - 1) * n;
                break;
            }

            if (len > n)
            {
                std::vector<int> tmp;
                for(int i = 0; i <= n; i++)
                {
                    int value = q.top() - 1;
                    q.pop();
                    if(value)
                        tmp.push_back(value);

                    res++;
                }
                for(const auto& val : tmp)
                {
                    q.push(val);
                }
            }
            else
            {
                std::vector<int> tmp;
                for(int i = 0; i < len; i++)
                {
                    int value = q.top() - 1;
                    q.pop();
                    if(value)
                        tmp.push_back(value);

                    res += 1;
                }
                if(tmp.size())
                    res += abs(len - (n + 1));
                for(const auto& val : tmp)
                {
                    q.push(val);
                }
            }
        }

        return res;
    }
};

/**
 * 3, 3
 * 2
 * 
 * 
 */
TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<char> tasks = {'A','A','A','B','B','B'};
        EXPECT_EQ(8, obj->leastInterval(tasks, 2));
    }
    /*{
        std::vector<char> tasks = {'A','A','A','A','A','A','B','C','D','E','F','G'};
        EXPECT_EQ(16, obj->leastInterval(tasks, 2));
    }*/
}

