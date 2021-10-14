#ifndef DSA_COMMON_H
#define DSA_COMMON_H

#include <vector>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}

    /**
     * Delete a list with head node recursively.
     * @note Only for list with no cycle.
     *
     * @param head head node to delete
     */
    static void deleteList(ListNode *&head);

    /**
     * Make a list using vector.
     *
     * @param nodes vector to create the list
     * @param cyclePosition position to indicate whether should create a cycle.
     *                      -1 means no cycle, default value. Start with zero.
     * @return head node pointer of the list
     */
    static ListNode *makeList(const std::vector<int> &nodes, int cyclePosition = -1);

    /**
     *  Delete a cycle list.
     *
     * @param head head node to delete
     */
    static void deleteCycleList(ListNode *&head);
};

class Utils {
public:
    /**
     * Check an array whether is in ascending or descending order.
     *
     * @param nums array to check
     * @param ascending whether to check in ascending order
     * @return whether the array is in the right order
     */
    static bool isOrderly(std::vector<int> &nums, bool ascending);
};

#endif // DSA_COMMON_H
