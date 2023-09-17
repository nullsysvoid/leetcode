#include <gtest/gtest.h>
#include <bits/stdc++.h>

class Solution {
public:
    struct Node
    {
        int len;
        int node;
        int mask;
    };
    
    int shortestPathLength(std::vector<std::vector<int>>& graph)
    {       
        int res = 0;
        
        std::queue<Node> q;
        std::set<std::pair<int,int>> visited;
        
        for(int i = 0; i < graph.size(); i++)
        {
            int mask = 1 << i;
            Node node {
                .len = 0,
                .node = i,
                .mask = mask
            };
            
            q.push(node);
            visited.insert({i, mask});
        }

        int allMask = (1 << graph.size()) - 1;
        
        while(!q.empty())
        {
            auto currentNode = q.front();
            q.pop();
			
            if(currentNode.mask == allMask)
            {
                return currentNode.len;
            }
            
            for(auto connectedNode : graph[currentNode.node])
            {
                int mask = currentNode.mask | (1 << connectedNode);
                if(visited.find({connectedNode, mask}) == visited.end())
                {
                    visited.insert({connectedNode, mask});
                    Node node {
                        .len = currentNode.len + 1,
                        .node = connectedNode,
                        .mask = mask
                    };
                    q.push(node);
                }
            }           
        }
              
        return res;       
    }
};

TEST(Test, Smoke) {
    std::shared_ptr<Solution> obj = std::make_shared<Solution>();
    {
        std::vector<std::vector<int>> graph{
            {1},
            {0,2,4},
            {1,3,4},
            {2},
            {1,2}
        };

        ASSERT_EQ(4, obj->shortestPathLength(graph));
    }
}
