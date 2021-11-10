#include <gtest/gtest.h>

#include <algorithm>
#include <climits>
#include <deque>
#include <list>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;
namespace lc232 {
/**
 * https://leetcode-cn.com/problems/implement-queue-using-stacks/
 * 使用两个栈来实现队列
 */
class MyQueue {
public:
    MyQueue() = default;

    void push(int x) {
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        stack1.push(x);
    }

    int pop() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int result = stack2.top();
        stack2.pop();
        return result;
    }

    int peek() {
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        return stack2.top();
    }

    bool empty() {
        return stack1.empty() && stack2.empty();
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

/**
 * 更高效的实现，仅在peek或者pop的时候，才需要进行顺序的交换
 */
class MyQueue2 {
public:
    MyQueue2() = default;

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        if (outStack.empty()) {
            in2out();
        }
        int result = outStack.top();
        outStack.pop();
        return result;
    }

    int peek() {
        if (outStack.empty()) {
            in2out();
        }
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && inStack.empty();
    }

private:
    stack<int> inStack;
    stack<int> outStack;

private:
    void in2out() {
        while (!inStack.empty()) {
            outStack.push(inStack.top());
            inStack.pop();
        }
    }
};
} // namespace lc232

class LC232Tests : public ::testing::Test {
};

TEST_F(LC232Tests, queue1) {
    lc232::MyQueue queue;
    EXPECT_TRUE(queue.empty());
    queue.push(1);
    queue.push(2);
    EXPECT_EQ(queue.peek(), 1);
    queue.push(3);
    EXPECT_EQ(queue.pop(), 1);
    EXPECT_FALSE(queue.empty());
    queue.push(4);
    EXPECT_EQ(queue.pop(), 2);
    EXPECT_EQ(queue.pop(), 3);
    EXPECT_EQ(queue.peek(), 4);
    EXPECT_EQ(queue.pop(), 4);
    EXPECT_TRUE(queue.empty());
}

TEST_F(LC232Tests, queue2) {
    lc232::MyQueue2 queue;
    EXPECT_TRUE(queue.empty());
    queue.push(1);
    queue.push(2);
    EXPECT_EQ(queue.peek(), 1);
    queue.push(3);
    EXPECT_EQ(queue.pop(), 1);
    EXPECT_FALSE(queue.empty());
    queue.push(4);
    EXPECT_EQ(queue.pop(), 2);
    EXPECT_EQ(queue.pop(), 3);
    EXPECT_EQ(queue.peek(), 4);
    EXPECT_EQ(queue.pop(), 4);
    EXPECT_TRUE(queue.empty());
}