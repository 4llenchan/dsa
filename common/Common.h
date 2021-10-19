#ifndef DSA_COMMON_H
#define DSA_COMMON_H

#include <string>
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

class MathUtils {
public:
    /**
     * 将一个十进制数转化成0123456789abcdefghijklmnopqrstuvwxyz所表达的36进制字符串
     *
     * @param decimal 十进制数
     * @return std::string表示一个36进制的字符串
     */
    static std::string convertDecimal(uint32_t decimal);

    /**
     * 将一个0123456789abcdefghijklmnopqrstuvwxyz所表达的36进制字符串转化成十进制数
     * 若str中含有非法字符，统一返回0
     *
     * @param str 36进制表示的字符串
     * @return 对应的十进制数
     */
    static uint32_t convertThirtySix(const std::string &str);
};

#endif // DSA_COMMON_H
