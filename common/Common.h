#ifndef DSA_COMMON_H
#define DSA_COMMON_H

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

void deleteList(ListNode *&head) {
    if (head) {
        if (head->next) {
            deleteList(head->next);
        }
        delete head;
        head = nullptr;
    }
}

#endif //DSA_COMMON_H
