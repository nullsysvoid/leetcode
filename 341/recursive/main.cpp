#include <gtest/gtest.h>
#include <bits/stdc++.h>

class NestedInteger {
    public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;
    
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    void helper(const NestedInteger& value)
    {
        if (value.isInteger())
        {
            const auto tmp = value.getInteger();
            list.push_back(tmp);
        }
        else
        {
            for(auto i : value.getList())
                helper(i);
        }

    }

    NestedIterator(std::vector<NestedInteger> &nestedList) {
        for(const auto& ni : nestedList)
            helper(ni);
    }
    
    int next() {
        const auto value = list[iter];
        iter++;
        return value;
    }
    
    bool hasNext() {
        return iter < list.size();
    }
private:
    std::vector<int> list;
    int iter = 0;
};

TEST(Test, Smoke) {
}

