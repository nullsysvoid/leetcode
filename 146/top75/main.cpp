#include <gtest/gtest.h>
#include <bits/stdc++.h>

class LRUCache {
public:
    struct Kv
    {
        int key;
        int value;
    };

    std::unordered_map<int, std::list<Kv>::iterator> mp;
    std::list<Kv> list;
    int m_capacity;

    LRUCache(int capacity) {
        m_capacity = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it != mp.end())
        {
            int key = it->second->key;
            int value = it->second->value;
            list.erase(it->second);
            list.push_front({key, value});
            mp[key] = list.begin();
            return value;
        }

        return -1;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it != mp.end())
        {
            list.erase(it->second);
            list.push_front({key, value});
            mp[key] = list.begin();
            return;
        }

        if (mp.size() == m_capacity)
        {
            mp.erase(list.back().key);
            list.pop_back();
        }
        list.push_front({key, value});
        mp[key] = list.begin();
    }
};

TEST(Test, Smoke) {
    {
        std::shared_ptr<LRUCache> obj = std::make_shared<LRUCache>(2);

        //["LRUCache","put","put","get","put","get","put","get","get","get"]
        //[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
        //[null,null,null,1,null,-1,null,-1,3,4]
        obj->put(1, 1);
        obj->put(2, 2);
        EXPECT_EQ(1, obj->get(1));
        obj->put(3, 3);
        
        EXPECT_EQ(-1, obj->get(2));
        obj->put(4, 4);
        EXPECT_EQ(-1, obj->get(1));
        EXPECT_EQ(3, obj->get(3));
        EXPECT_EQ(4, obj->get(4));
    }
    {
        std::shared_ptr<LRUCache> obj = std::make_shared<LRUCache>(1);

        //["LRUCache","put","get"]
        //[[1],[2,1],[2]]
        //[null,null,1]
        obj->put(2, 1);
        EXPECT_EQ(1, obj->get(2));
    }
    {
        std::shared_ptr<LRUCache> obj = std::make_shared<LRUCache>(2);

        //["LRUCache","get","put","get","put","put","get","get"]
        //[[2],[2],[2,6],[1],[1,5],[1,2],[1],[2]]
        //[null,-1,null,-1,null,null,2,6]
        EXPECT_EQ(-1, obj->get(2));
        obj->put(2, 6);
        EXPECT_EQ(-1, obj->get(1));
        obj->put(1, 5);
        obj->put(1, 2);
        EXPECT_EQ(2, obj->get(1));
        EXPECT_EQ(6, obj->get(2));
    }
}