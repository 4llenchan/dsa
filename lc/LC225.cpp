#include <gtest/gtest.h>

#include <algorithm>
#include <climits>
#include <deque>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

#include "Common.h"

using namespace std;
namespace lc225 {
/**
 * https://leetcode-cn.com/problems/implement-stack-using-queues/
 * 两个队列实现栈，也是用单个队列来实现
 */
class MyStack {
public:
    MyStack() = default;

    void push(int x) {
        queue2_.push(x);
        while (!queue1_.empty()) {
            queue2_.push(queue1_.front());
            queue1_.pop();
        }
        /* swap函数进行交换效率更高 */
        swap(queue1_, queue2_);
        /* 单队列实现版本 */
        //        int n = (int)queue1_.size();
        //        queue1_.push(x);
        //        while (n > 0) {
        //            queue1_.push(queue1_.front());
        //            queue1_.pop();
        //            n--;
        //        }
    }

    int pop() {
        int top = queue1_.front();
        queue1_.pop();
        return top;
    }

    int top() {
        return queue1_.front();
    }

    bool empty() {
        return queue1_.empty();
    }

private:
    queue<int> queue1_; /* 队列1保存元素，其顺序和栈的顺序相同 */
    queue<int> queue2_; /* 队列2辅助入栈时进行反转的动作 */
};
} // namespace lc225

class LC225Tests : public ::testing::Test {
protected:
    lc225::MyStack myStack;
};

TEST_F(LC225Tests, case1) {
    myStack.push(1);
    myStack.push(2);
    EXPECT_EQ(myStack.pop(), 2);
    EXPECT_EQ(myStack.pop(), 1);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    EXPECT_EQ(myStack.pop(), 5);
    myStack.push(5);
    EXPECT_EQ(myStack.pop(), 5);
    EXPECT_FALSE(myStack.empty());
}