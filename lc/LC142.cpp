#include <gtest/gtest.h>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <numeric>

#include "Common.h"

using namespace std;

/**
 * https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * 快慢指针找环的第一个节点（出入口）
 */
class Solution1 {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *p = head;
                while (p != slow) {
                    p = p->next;
                    slow = slow->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};

class LC142Tests : public ::testing::Test {
protected:
    Solution1 solution1;
};

TEST_F(LC142Tests, case1) {
    auto *head = ListNode::makeList(vector<int>{3, 2, 0, -4}, 1);
    auto *detect = solution1.detectCycle(head);
    EXPECT_NE(detect, nullptr);
    if (detect) {
        EXPECT_EQ(detect->val, 2);
    }
    ListNode::deleteCycleList(head);
}