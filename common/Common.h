#ifndef DSA_COMMON_H
#define DSA_COMMON_H

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * Delete a list with head node recursively.
 *
 * @param head head node to delete
 */
extern void deleteList(ListNode *&head);

#endif // DSA_COMMON_H
