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
namespace lc94 {
/**
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 * 二叉树中序遍历，递归实现
 */
class Solution1 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }

    void inorder(TreeNode* root, vector<int>& result) {
        if (!root) {
            return;
        }
        inorder(root->left, result);
        result.emplace_back(root->val);
        inorder(root->right, result);
    }
};

/**
 * 二叉树中序遍历，非递归实现，模拟递归实现时的栈的过程
 */
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack;
        while (root || !stack.empty()) {
            while (root) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            result.push_back(root->val);
            root = root->right;
        }
        return result;
    }
};

} // namespace lc94

class LC94Tests : public ::testing::Test {
protected:
    lc94::Solution1 solution1;
    lc94::Solution2 solution2;
};

TEST_F(LC94Tests, case1) {
    auto root = new TreeNode(1);
    root->right = new TreeNode(2, new TreeNode(3), nullptr);
    vector<int> expect{1, 3, 2};
    auto result1 = solution1.inorderTraversal(root);
    auto result2 = solution2.inorderTraversal(root);
    EXPECT_EQ(expect, result1);
    EXPECT_EQ(expect, result2);
    TreeNode::deleteTree(root);
}