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
namespace lc144 {
/**
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
 * 二叉树前序遍历，递归实现
 */
class Solution1 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }

    void preorder(TreeNode *root, vector<int> &result) {
        if (!root) {
            return;
        }
        result.push_back(root->val);
        preorder(root->left, result);
        preorder(root->right, result);
    }
};

/**
 * 二叉树前序遍历，非递归实现
 */
class Solution2 {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> stack;
        if (root) {
            stack.push(root);
        }
        while (!stack.empty()) {
            auto node = stack.top();
            stack.pop();
            result.push_back(node->val);
            /* stack是后进先出，所以先访问右节点 */
            if (node->right) {
                stack.push(node->right);
            }
            if (node->left) {
                stack.push(node->left);
            }
        }
        return result;
    }
};
} // namespace lc144

class LC144Tests : public ::testing::Test {
protected:
    lc144::Solution1 solution1;
    lc144::Solution2 solution2;
};

TEST_F(LC144Tests, case1) {
    auto root = new TreeNode(1);
    root->right = new TreeNode(2, new TreeNode(3), nullptr);
    vector<int> expect{1, 2, 3};
    auto result1 = solution1.preorderTraversal(root);
    EXPECT_EQ(expect, result1);
    auto result2 = solution2.preorderTraversal(root);
    EXPECT_EQ(expect, result2);
    TreeNode::deleteTree(root);
}