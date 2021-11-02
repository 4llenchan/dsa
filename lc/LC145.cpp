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
namespace lc145 {
/**
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/
 * 二叉树后序遍历，递归实现
 */
class Solution1 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorder(root, result);
        return result;
    }

    void postorder(TreeNode* root, vector<int>& result) {
        if (!root) {
            return;
        }
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->val);
    }
};

/**
 * 二叉树后序遍历，非递归实现
 */
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> stack;
        /* 用一个指针记录上一个输出的节点，使得可以判断节点是需要继续遍历右节点还是输出 */
        TreeNode* prev = nullptr;
        while (root || !stack.empty()) {
            while (root) {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            if (!root->right || root->right == prev) {
                prev = root;
                stack.pop();
                result.push_back(root->val);
                root = nullptr;
            } else {
                root = root->right;
            }
        }
        return result;
    }
};
} // namespace lc145

class LC145Tests : public ::testing::Test {
protected:
    lc145::Solution1 solution1;
    lc145::Solution2 solution2;
};

TEST_F(LC145Tests, case1) {
    auto root = new TreeNode(1);
    root->right = new TreeNode(2, new TreeNode(3), nullptr);
    vector<int> expect{3, 2, 1};
    auto result1 = solution1.postorderTraversal(root);
    auto result2 = solution2.postorderTraversal(root);
    EXPECT_EQ(expect, result1);
    EXPECT_EQ(expect, result2);
    TreeNode::deleteTree(root);
}