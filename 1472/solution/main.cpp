#include <gtest/gtest.h>
#include <bits/stdc++.h>
#include <utils/utils.h>

class BrowserHistory {
public:
    BrowserHistory(std::string homepage)
        : m_current(homepage)
    {
    }
    
    void visit(std::string url) {
        while(!forwardSt.empty())
            forwardSt.pop();
        backSt.push(m_current);
        m_current = url;
    }
    
    std::string back(int steps) {
        while(!backSt.empty() && steps--)
        {
            forwardSt.push(m_current);
            m_current = backSt.top();
            backSt.pop();
        }
        return m_current;
    }
    
    std::string forward(int steps) {
        while(!forwardSt.empty() && steps--)
        {
            backSt.push(m_current);
            m_current = forwardSt.top();
            forwardSt.pop();
        }
        return m_current;
    }
private:
    std::stack<std::string> backSt, forwardSt;
    std::string m_current;
};

TEST(Test, Smoke) {
    std::shared_ptr<BrowserHistory> browserHistory = std::make_shared<BrowserHistory>("leetcode.com");
    {
        browserHistory->visit("google.com");                    // You are in "leetcode.com". Visit "google.com"
        browserHistory->visit("facebook.com");                  // You are in "google.com". Visit "facebook.com"
        browserHistory->visit("youtube.com");                   // You are in "facebook.com". Visit "youtube.com"
        ASSERT_EQ("facebook.com", browserHistory->back(1));     // You are in "youtube.com", move back to "facebook.com" return "facebook.com"
        ASSERT_EQ("google.com", browserHistory->back(1));       // You are in "facebook.com", move back to "google.com" return "google.com"
        ASSERT_EQ("facebook.com", browserHistory->forward(1));  // You are in "google.com", move forward to "facebook.com" return "facebook.com"
        browserHistory->visit("linkedin.com");                  // You are in "facebook.com". Visit "linkedin.com"
        ASSERT_EQ("linkedin.com", browserHistory->forward(2));  // You are in "linkedin.com", you cannot move forward any steps.
        ASSERT_EQ("google.com", browserHistory->back(2));       // You are in "linkedin.com", move back two steps to "facebook.com" then to "google.com". return "google.com"
        ASSERT_EQ("leetcode.com", browserHistory->back(7));     // You are in "google.com", you can move back only one step to "leetcode.com". return "leetcode.com"
    }
}
