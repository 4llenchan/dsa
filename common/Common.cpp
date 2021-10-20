#include "Common.h"

#include <cmath>
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
std::string MathUtils::convertDecimal(uint32_t decimal) {
    const int divisor = 36;
    auto convert = [](uint32_t x) {
        if (x < 10) {
            return char('0' + x);
        } else {
            return char('a' + x - 10);
        }
    };
    std::string result;
    do {
        uint32_t remainder = decimal % divisor;
        decimal = decimal / divisor;
        result.insert(0, 1, convert(remainder));
    } while (decimal > 0);
    return result;
}

uint32_t MathUtils::convertThirtySix(const std::string &str) {
    const int divisor = 36;
    uint32_t decimal = 0;
    int n = (int)str.size();
    int count = 0;
    auto convert = [](char c) -> int {
        if (c >= '0' && c <= '9') {
            return int(c - '0');
        } else if (c >= 'a' && c <= 'z') {
            return int(c - 'a' + 10);
        }
        return -1;
    };
    for (int i = n - 1; i >= 0; --i) {
        int num = convert(str[i]);
        if (num < 0) {
            return 0;
        }
        decimal += uint32_t(num * std::pow(divisor, count));
        count++;
    }
    return decimal;
}
