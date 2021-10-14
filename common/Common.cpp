#include "Common.h"

#include <unordered_set>

void ListNode::deleteList(ListNode *&head) {
    if (head) {
        if (head->next) {
            deleteList(head->next);
        }
        delete head;
        head = nullptr;
    }
}

ListNode *ListNode::makeList(const std::vector<int> &nodes, int cyclePosition) {
    ListNode fakeHead(0);
    auto *tail = &fakeHead;
    ListNode *cycle = nullptr;
    for (int i = 0; i < nodes.size(); ++i) {
        auto *node = new ListNode(nodes[i]);
        tail->next = node;
        tail = node;
        if (cyclePosition == i) {
            cycle = node;
        }
    }
    tail->next = cycle;
    return fakeHead.next;
}

void ListNode::deleteCycleList(ListNode *&head) {
    std::unordered_set<ListNode *> occurance;
    auto *current = head;
    while (current) {
        auto *tmp = current;
        /* 找到了已经出现过的节点，可跳出循环 */
        if (occurance.find(tmp) != occurance.end()) {
            break;
        }
        current = current->next;
        /* 记录已删除的节点，遇到循环时可跳出 */
        occurance.emplace(tmp);
        delete tmp;
    }
    head = nullptr;
}

bool Utils::isOrderly(std::vector<int> &nums, bool ascending) {
    for (int i = 1; i < nums.size(); ++i) {
        if (ascending && nums[i] < nums[i - 1]) {
            return false;
        }
        if (!ascending && nums[i] > nums[i - 1]) {
            return false;
        }
    }
    return true;
}
