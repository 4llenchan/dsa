#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "Common.h"

using namespace std;

class Solution {
public:
    vector<int> reversePrint(ListNode *head) {
        vector<int> result;
        if (head) {
            reverse(head, result);
        }
        return result;
    }

    void reverse(ListNode *head, vector<int> &result) {
        if (head->next) {
            reverse(head->next, result);
        }
        result.push_back(head->val);
    }
};

class OF6Tests : public ::testing::Test {
protected:
    Solution solution;
};

TEST_F(OF6Tests, normal) {
    auto *head = new ListNode(1);
    auto *node1 = new ListNode(3);
    auto *node2 = new ListNode(2);
    node1->next = node2;
    head->next = node1;
    auto result = solution.reversePrint(head);
    vector<int> expect = {2, 3, 1};
    EXPECT_EQ(result, expect);
    ListNode::deleteList(head);
}